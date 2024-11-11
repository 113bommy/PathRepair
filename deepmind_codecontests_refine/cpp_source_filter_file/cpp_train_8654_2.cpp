#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, q, s[100005], d[100005], tot[100005] = {0}, i, l, r, x;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> s[i];
  sort(s, s + n);
  for (i = 1; i < n; i++) d[i] = s[i + 1] - s[i];
  sort(d + 1, d + n);
  for (i = 1; i < n; i++) tot[i] = tot[i - 1] + d[i];
  cin >> q;
  while (q--) {
    cin >> l >> r;
    x = r - l + 1;
    int p = lower_bound(d + 1, d + n, x) - d;
    cout << tot[p - 1] + (n - p + 1) * x << " ";
  }
}
