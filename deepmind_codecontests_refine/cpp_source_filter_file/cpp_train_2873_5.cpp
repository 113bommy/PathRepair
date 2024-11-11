#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:160777216")
using namespace std;
long long MOD = 1000000007;
int n, m, q, i, j, k;
int a[500000];
long long p[500000];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  long long ans = 0;
  long long cur = 0;
  long long po = 2;
  for (i = n - 2; i >= 0; i--) {
    cur = cur * 2 + (po - 1) * (a[i + 1] - a[i]);
    cur %= MOD;
    ans += cur;
    ans %= MOD;
    po *= 2;
    po % -MOD;
  }
  cout << ans << endl;
  return 0;
}
