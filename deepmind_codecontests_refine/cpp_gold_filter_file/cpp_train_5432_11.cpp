#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln = '\n';
template <class T1, class T2>
inline bool chmax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T1, class T2>
inline bool chmin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
inline int topbit(int x) { return x == 0 ? -1 : 31 - __builtin_clz(x); }
inline int topbit(long long x) { return x == 0 ? -1 : 63 - __builtin_clzll(x); }
inline int botbit(int x) { return x == 0 ? 32 : __builtin_ctz(x); }
inline int botbit(long long x) { return x == 0 ? 64 : __builtin_ctzll(x); }
inline int popcount(int x) { return __builtin_popcount(x); }
inline int popcount(long long x) { return __builtin_popcountll(x); }
inline int kthbit(long long x, int k) { return (x >> k) & 1; }
inline void print() { cout << "\n"; }
template <class T>
inline void print(const vector<T> &v) {
  for (auto itr = v.begin(); itr != v.end(); ++itr) cout << *itr << " ";
  print();
}
template <class T, class... Args>
inline void print(const T &x, const Args &...args) {
  cout << x << " ";
  print(args...);
}
inline void debug() {}
template <class T>
inline void debug(const vector<T> &v) {}
template <class T, class... Args>
inline void debug(const T &x, const Args &...args) {}
const int dx[6] = {-2, -1, 0, 2, 1, 0};
const int dy[6] = {0, -1, -2, 0, 1, 2};
int main() {
  int N;
  cin >> N;
  vector<vector<int>> ans(N, vector<int>(N, -1));
  ans[0][0] = 1;
  ans[N - 1][N - 1] = 0;
  auto query = [](int x, int y, int nx, int ny) {
    cout << "? ";
    if (x <= nx and y <= ny) {
      cout << x + 1 << " " << y + 1 << " " << nx + 1 << " " << ny + 1 << endl;
    } else {
      cout << nx + 1 << " " << ny + 1 << " " << x + 1 << " " << y + 1 << endl;
    }
    int ret;
    cin >> ret;
    return ret;
  };
  queue<pii> que;
  que.emplace(0, 0);
  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();
    for (int k = 0; k < (6); ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if (ans[nx][ny] != -1) continue;
      int ret = query(x, y, nx, ny);
      if (ret)
        ans[nx][ny] = ans[x][y];
      else
        ans[nx][ny] = 1 - ans[x][y];
      que.emplace(nx, ny);
    }
  }
  for (int i = 0; i < (N - 1); ++i) {
    for (int j = 0; j < (N - 1); ++j) {
      if (ans[i][j] != -1) continue;
      if (!que.empty()) continue;
      if (ans[i + 1][j] != ans[i][j + 1]) {
        if (j == 0) {
          int ret = query(i, j, i + 1, j + 2);
          if (ret) {
            ans[i][j] = ans[i + 1][j + 2];
            que.emplace(i, j);
          } else {
            ans[i][j] = 1 - ans[i + 1][j + 2];
            que.emplace(i, j);
          }
        } else {
          int ret = query(i, j - 1, i + 1, j + 1);
          if (ret) {
            ans[i + 1][j + 1] = ans[i][j - 1];
            que.emplace(i + 1, j + 1);
          } else {
            ans[i + 1][j + 1] = 1 - ans[i][j - 1];
            que.emplace(i + 1, j + 1);
          }
        }
      }
    }
  }
  for (int i = 0; i < (N - 2); ++i) {
    for (int j = 0; j < (N - 2); ++j) {
      if (ans[i][j] == -1) continue;
      if (!que.empty()) continue;
      if (ans[i][j] != ans[i + 2][j + 2]) {
        int ret1 = query(i, j, i + 2, j + 1);
        if (ret1) {
          ans[i + 2][j + 1] = ans[i][j];
          ans[i + 1][j] = ans[i + 1][j + 1];
          ans[i][j + 1] = ans[i + 1][j + 1];
          que.emplace(i + 2, j + 1);
          que.emplace(i + 1, j);
          que.emplace(i, j + 1);
          break;
        }
        int ret2 = query(i, j, i + 1, j + 2);
        if (ret2) {
          ans[i + 1][j + 2] = ans[i][j];
          ans[i + 1][j] = ans[i + 1][j + 1];
          ans[i][j + 1] = ans[i + 1][j + 1];
          que.emplace(i + 1, j + 2);
          que.emplace(i + 1, j);
          que.emplace(i, j + 1);
          break;
        }
        int ret3 = query(i + 2, j + 2, i, j + 1);
        if (ret3) {
          ans[i][j + 1] = ans[i + 2][j + 2];
          ans[i + 2][j + 1] = ans[i + 1][j + 1];
          ans[i + 1][j + 2] = ans[i + 1][j + 1];
          que.emplace(i, j + 1);
          que.emplace(i + 2, j + 1);
          que.emplace(i + 1, j + 2);
          break;
        }
        int ret4 = query(i + 2, j + 2, i + 1, j);
        if (ret4) {
          ans[i + 1][j] = ans[i + 2][j + 2];
          ans[i + 2][j + 1] = ans[i + 1][j + 1];
          ans[i + 1][j + 2] = ans[i + 1][j + 1];
          que.emplace(i + 1, j);
          que.emplace(i + 2, j + 1);
          que.emplace(i + 1, j + 2);
          break;
        }
        if (ans[i + 1][j + 1] == ans[i][j]) {
          ans[i + 1][j + 2] = ans[i + 2][j + 2];
          ans[i + 2][j + 1] = ans[i + 2][j + 2];
          que.emplace(i + 1, j + 2);
          que.emplace(i + 2, j + 1);
        } else {
          ans[i][j + 1] = ans[i + 1][j] = ans[i][j];
          que.emplace(i, j + 1);
          que.emplace(i + 1, j);
        }
      }
    }
  }
  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();
    for (int k = 0; k < (6); ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if (ans[nx][ny] != -1) continue;
      int ret = query(x, y, nx, ny);
      if (ret)
        ans[nx][ny] = ans[x][y];
      else
        ans[nx][ny] = 1 - ans[x][y];
      que.emplace(nx, ny);
    }
  }
  cout << "!" << endl;
  for (int i = 0; i < (N); ++i) {
    for (int j = 0; j < (N); ++j) cout << ans[i][j];
    cout << endl;
  }
}
