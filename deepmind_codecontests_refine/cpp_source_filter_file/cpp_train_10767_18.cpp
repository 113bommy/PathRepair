#include <bits/stdc++.h>
using namespace std;
const pair<int, int> DD[] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                             {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
template <class T>
T smin(T &a, T b) {
  if (a > b) a = b;
  return a;
}
template <class T>
T smax(T &a, T b) {
  if (a < b) a = b;
  return a;
}
int main(void) {
  srand(time(0));
  cout << fixed << setprecision(7);
  cerr << fixed << setprecision(7);
  int n, m;
  cin >> n >> m;
  static int C[1 << 18][105];
  const int mod = 1e9 + 7;
  const int N = 2e5;
  const int K = 100;
  for (int i = 0; i <= N; ++i)
    for (int j = 0; j <= min(i, K); ++j)
      C[i][j] = (!i || !j ? 1 : C[i - 1][j] + C[i - 1][j - 1]) % mod;
  static int s[1 << 20];
  static int D[1 << 17][105];
  for (int i = 1; i <= n; ++i) cin >> s[i];
  while (m--) {
    int l, r, k;
    cin >> l >> r >> k;
    k += 1;
    (D[l][k] += 1) %= mod;
    for (int i = 1; i <= k; ++i)
      (D[r + 1][i] += mod - C[r - l + k - i][k - i]) %= mod;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 100; j >= 0; --j)
      (D[i][j] += (j != 0) * D[i - 1][j]) %= mod,
          (D[i][j] += D[i][j + 1]) %= mod;
  for (int i = 1; i <= n; ++i) {
    int ans = (s[i] + D[i][0]) % mod;
    cout << ans << " \n"[i == n];
  }
  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
  return 0;
}
