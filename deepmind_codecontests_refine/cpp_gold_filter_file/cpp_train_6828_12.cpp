#include <bits/stdc++.h>
using namespace std;
void rs(int &x) { scanf("%d", &x); }
void rsl(long long &x) { scanf("%I64d", &x); }
void rsd(double &x) { scanf("%lf", &x); }
void rss(char *str) { scanf("%s", str); }
void ws(int &x) { printf("%d ", x); }
void wsl(long long &x) { printf("%I64d ", x); }
void wsd(double &x) { printf("%lf ", x); }
void wss(char *str) { printf("%s ", str); }
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int const N = (1e5) + 5;
int const mod = (1e9) + 7;
int a[N];
int dp[322][N];
int main() {
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  ofstream out("output.txt");
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= 320; ++i) {
    for (int j = n - 1; j >= 0; --j) {
      if (j + i + a[j] >= n) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i][j + i + a[j]] + 1;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int p, k;
    cin >> p >> k;
    p--;
    if (k <= 320) {
      cout << dp[k][p] << "\n";
    } else {
      int cnt = 0;
      while (p < n) {
        ++cnt;
        p += a[p] + k;
      }
      cout << cnt << "\n";
    }
  }
  return 0;
}
