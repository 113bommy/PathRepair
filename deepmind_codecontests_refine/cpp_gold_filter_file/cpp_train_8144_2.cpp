#include <bits/stdc++.h>
using namespace std;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
  std::fill((T *)array, (T *)(array + N), val);
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int a[1000010];
vector<int> res;
int z[20];
set<int> g[(1 << 20) + 1000000];
int n;
void dfs(int id) {
  for (auto x = g[id].begin(); x != g[id].end();) {
    g[*x].erase(id);
    int k = *x;
    g[id].erase(k);
    dfs(k);
    x = g[id].lower_bound(k);
  }
  if (id < 2 * n) res.push_back(id);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  int ppp = 2;
  for (int i = 0; i < (int)(20); ++i) {
    z[i] = ppp - 1;
    ppp *= 2;
  }
  for (int i = 0; i < (int)(n); ++i) {
    int s, t;
    cin >> s >> t;
    a[i * 2] = s;
    a[i * 2 + 1] = t;
  }
  int ans = -1;
  for (int k = 19; k >= 0; k--) {
    int ss[(1 << 20) + 1000000] = {};
    for (int i = 0; i < (int)(n); ++i) {
      ss[2 * i]++;
      ss[2 * i + 1]++;
    }
    for (int i = 0; i < (int)(2 * n); ++i) {
      ss[i]++;
      ss[2 * n + (z[k] & a[i])]++;
    }
    bool fff = 0;
    for (int i = 0; i < (int)((1 << 20) + 1000000); ++i) {
      if (ss[i] % 2 != 0) fff = 1;
    }
    if (fff) continue;
    for (int i = 0; i < (int)((1 << 20) + 1000000); ++i) {
      g[i].clear();
    }
    for (int i = 0; i < (int)(n); ++i) {
      g[2 * i].insert(2 * i + 1);
      g[2 * i + 1].insert(2 * i);
    }
    for (int i = 0; i < (int)(2 * n); ++i) {
      g[i].insert(2 * n + (z[k] & a[i]));
      g[2 * n + (z[k] & a[i])].insert(i);
    }
    dfs(0);
    if (res.size() == 2 * n + 1) {
      cout << k + 1 << "\n";
      if (res[0] / 2 == res[1] / 2) {
        for (int i = 0; i < (int)(2 * n); ++i) {
          cout << res[i] + 1 << " ";
        }
      } else {
        for (int i = 0; i < (int)(2 * n); ++i) {
          cout << res[i + 1] + 1 << " ";
        }
      }
      cout << "\n";
      return 0;
    } else {
      res.clear();
    }
  }
  cout << 0 << "\n";
  for (int i = 0; i < (int)(2 * n); ++i) {
    cout << i + 1 << " ";
  }
  cout << "\n";
  return 0;
}
