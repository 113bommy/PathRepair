#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const int Inf = 0x3F3F3F3F;
const int Mod = 1e9 + 7;
const int MAXN = 2e5 + 9;
long long n, a[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  long long p;
  for (long long i = 0; i < 2 * n; i++) {
    long long k;
    cin >> k;
    if (i >= n)
      a[k] = i - n + 1;
    else
      a[k] = 0;
  }
  if (a[1]) {
    long long i, j;
    for (i = 2; a[i] == a[1] + i - 1; i++)
      ;
    if (a[i - 1] == n) {
      for (j = i; j <= n && a[j] <= j - i; j++)
        ;
      if (j > n) {
        cout << n - i + 1;
        return 0;
      }
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) ans = max(ans, a[i] - i + 1 + n);
  cout << ans;
  return 0;
}
