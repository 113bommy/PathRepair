#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int sieve[maxn], dp[maxn];
void init() {
  memset(sieve, 1, sizeof(sieve));
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i < maxn; i++)
    if (sieve[i])
      for (int j = 2 * i; j < maxn; j += i) sieve[j] = 0;
}
int main() {
  init();
  vector<int> prime;
  int n, ans = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    vector<int> p;
    if (sieve[a[i]]) p.push_back(a[i]);
    for (int j = 2; j * j <= a[i]; j++)
      if (a[i] % j == 0) {
        if (sieve[j]) p.push_back(j);
        if (j * j != a[i] and sieve[a[i] / j]) p.push_back(a[i] / j);
      }
    int tmp = 0;
    for (int j = 0; j < (int)p.size(); j++) tmp = max(tmp, dp[p[j]]);
    for (int j = 0; j < (int)p.size(); j++) dp[p[j]] = tmp + 1;
  }
  for (int i = 0; i < maxn; i++) ans = max(ans, dp[i]);
  cout << max(ans, 1);
  return 0;
}
