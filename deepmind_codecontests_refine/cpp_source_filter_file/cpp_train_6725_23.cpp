#include <bits/stdc++.h>
using namespace std;
struct cww {
  cww() {
    if (1) {
      ios::sync_with_stdio(false);
      cin.tie(0);
    }
  }
} star;
template <typename T>
inline bool chmin(T &l, T r) {
  bool a = l > r;
  if (a) l = r;
  return a;
}
template <typename T>
inline bool chmax(T &l, T r) {
  bool a = l < r;
  if (a) l = r;
  return a;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &it : v) is >> it;
  return is;
}
vector<vector<vector<vector<long long> > > > ori(
    53, vector<vector<vector<long long> > >(
            53, vector<vector<long long> >(53, vector<long long>(53, 0))));
long long aa(int x) { return x * (x - 1) / 2; }
long long aaa(int x) { return x * (x - 1) * (x - 2) / 6; }
long long aab(int x, int y) { return y * x * (x - 1) / 2; }
const int mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  vector<vector<vector<vector<long long> > > > dp =
      vector<vector<vector<vector<long long> > > >(
          2, vector<vector<vector<long long> > >(
                 2, vector<vector<long long> >(2, vector<long long>(2, 0))));
  vector<long long> d(n);
  cin >> d;
  if (d[0] == 2 && d[1] == 2) {
    dp[1][0][1][0] = 1;
  }
  if (d[0] == 2 && d[1] == 3) {
    dp[1][0][0][1] = 1;
  }
  if (d[0] == 3 && d[1] == 2) {
    dp[0][1][1][0] = 1;
  }
  if (d[0] == 3 && d[1] == 3) {
    dp[0][1][0][1] = 1;
  }
  for (int i = (2); i < (n); i++) {
    vector<vector<vector<vector<long long> > > > nxt(
        i + 1, vector<vector<vector<long long> > >(
                   i + 1, vector<vector<long long> >(
                              i + 1, vector<long long>(i + 1, 0))));
    if (d[i] == 3) {
      for (int x = (0); x < (i); x++)
        for (int y = (0); y < (i); y++) {
          if (x) nxt[x - 1][y][0][1] += x * dp[0][0][x][y];
          if (y) nxt[x][y - 1][0][1] += y * dp[0][0][x][y];
        }
      for (int a = (0); a < (i); a++)
        for (int b = (0); b < (i); b++)
          if (a + b <= i)
            for (int x = (0); x < (i); x++)
              if (a + b + x <= i)
                for (int y = (0); y < (i); y++)
                  if (a + b + x + y <= i) {
                    if (a) nxt[a - 1][b][x][y + 1] += a * dp[a][b][x][y];
                    if (b) nxt[a + 1][b - 1][x][y + 1] += b * dp[a][b][x][y];
                    if (a && x) nxt[a - 1][b][x][y] += a * x * dp[a][b][x][y];
                    if (a && y)
                      nxt[a - 1][b][x + 2][y - 1] += a * y * dp[a][b][x][y];
                    if (b && x)
                      nxt[a + 1][b - 1][x][y] += b * x * dp[a][b][x][y];
                    if (b && y)
                      nxt[a + 1][b - 1][x + 2][y - 1] += b * y * dp[a][b][x][y];
                    if (a && x >= 2)
                      nxt[a - 1][b][x - 2][y] += aab(x, a) * dp[a][b][x][y];
                    if (a && y >= 2)
                      nxt[a - 1][b][x + 2][y - 2] += aab(x, a) * dp[a][b][x][y];
                    if (b && x >= 2)
                      nxt[a + 1][b - 1][x - 2][y] += aab(x, b) * dp[a][b][x][y];
                    if (b && y >= 2)
                      nxt[a + 1][b - 1][x + 2][y - 2] +=
                          aab(y, b) * dp[a][b][x][y];
                    if (a && x && y)
                      nxt[a - 1][b][x][y - 1] += a * x * y * dp[a][b][x][y];
                    if (b && x && y)
                      nxt[a + 1][b - 1][x][y - 1] += b * x * y * dp[a][b][x][y];
                  }
    }
    if (d[i] == 2) {
      for (int x = (0); x < (i); x++)
        for (int y = (0); y < (i); y++) {
          if (x) nxt[x - 1][y][1][0] += x * dp[0][0][x][y];
          if (y) nxt[x + 1][y - 1][1][0] += y * dp[0][0][x][y];
        }
      for (int a = (0); a < (i); a++)
        for (int b = (0); b < (i); b++)
          if (a + b <= i)
            for (int x = (0); x < (i); x++)
              if (a + b + x <= i)
                for (int y = (0); y < (i); y++)
                  if (a + b + x + y <= i) {
                    if (a) nxt[a - 1][b][x + 1][y] += a * dp[a][b][x][y];
                    if (b) nxt[a + 1][b - 1][x + 1][y] += b * dp[a][b][x][y];
                    if (a && x)
                      nxt[a - 1][b][x - 1][y] += a * x * dp[a][b][x][y];
                    if (a && y)
                      nxt[a - 1][b][x + 1][y - 1] += a * y * dp[a][b][x][y];
                    if (b && x)
                      nxt[a + 1][b - 1][x - 1][y] += b * x * dp[a][b][x][y];
                    if (b && y)
                      nxt[a + 1][b - 1][x + 1][y - 1] += b * y * dp[a][b][x][y];
                  }
    }
    swap(dp, nxt);
    for (auto &a : dp)
      for (auto &b : a)
        for (auto &c : b)
          for (auto &it : c) it %= mod;
  }
  cout << dp[0][0][0][0] << endl;
  return 0;
}
