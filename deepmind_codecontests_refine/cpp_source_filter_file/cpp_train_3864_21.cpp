#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
void amax(X& x, const Y& y) {
  if (x < y) x = y;
}
template <class X, class Y>
void amin(X& x, const Y& y) {
  if (x > y) x = y;
}
const int INF = 1e9 + 10;
const long long INFL = (long long)1e18 + 10;
const int MOD = 998244353;
const int MAX = 1010;
struct item {
  int ms1, ms2, d;
};
const item items[] = {{0, 0, 0}, {0, 1, 1}, {0, 2, 1}, {0, 3, 1},
                      {1, 0, 0}, {1, 1, 0}, {1, 2, 2}, {1, 3, 0},
                      {2, 0, 0}, {2, 1, 2}, {2, 2, 0}, {2, 3, 0},
                      {3, 0, 1}, {3, 1, 1}, {3, 2, 1}, {3, 3, 0}};
const int abc[] = {0, 1, 1, 1, 0, 0, 2, 0, 0, 2, 0, 0, 1, 1, 1, 0};
int n, k;
int f[MAX][MAX][4];
int add(int a, int b) { return (a + b) % MOD; }
int dist(int ms1, int ms2) { return abc[ms1 * 4 + ms2]; }
void process() {
  cin >> n >> k;
  f[1][1][0] = f[1][1][3] = 1;
  f[1][2][1] = f[1][2][2] = 1;
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= 2 * i; j++)
      for (int ms1 = 0; ms1 < 4; ms1++) {
        for (int ms2 = 0; ms2 < 4; ms2++) {
          f[i + 1][j + dist(ms1, ms2)][ms2] =
              add(f[i + 1][j + dist(ms1, ms2)][ms2], f[i][j][ms1]);
        }
      }
  int res = 0;
  for (int ms = 0; ms < 4; ms++) res = add(res, f[n][k][ms]);
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  process();
}
