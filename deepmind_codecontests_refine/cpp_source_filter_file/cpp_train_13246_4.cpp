#include <bits/stdc++.h>
using namespace std;
const int base = 100003;
const long long MM = 1ll * 1000000007 * 1000000007;
const int maxc = 2e9;
int n, a[100001], f[100001];
void Solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) f[i] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < sqrt(i); j++)
      if (i % j == 0) {
        int k = i / j;
        if (a[k] < a[i]) f[i] = max(f[i], f[k] + 1);
        if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
      }
  }
  cout << *max_element(f + 1, f + n + 1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) Solve();
}
