#include <bits/stdc++.h>
using namespace std;
bool prime[1000001];
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  prime[0] = false;
  prime[1] = false;
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int suf[n + 1];
  suf[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i];
  }
  long long ans = suf[0];
  suf[0] = 0;
  sort(suf + 1, suf + n);
  reverse(suf + 1, suf + n);
  for (int i = 1; i < k; i++) {
    ans += suf[i];
  }
  cout << ans << "\n";
  ;
  return 0;
}
