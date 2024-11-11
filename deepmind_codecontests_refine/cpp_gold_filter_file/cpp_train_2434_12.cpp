#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  long long q;
  cin >> q;
  long long vals[n];
  for (int i = 0; i < n; i++) cin >> vals[i];
  sort(vals, vals + n);
  long long upds[n + 5];
  fill(upds, upds + n + 5, 0);
  while (q > 0) {
    q--;
    int l, r;
    cin >> l >> r;
    upds[l]++;
    upds[r + 1]--;
  }
  long long t = 0;
  long long vals2[n + 5];
  fill(vals2, vals2 + n, 0);
  for (int i = 1; i <= n; i++) {
    t += upds[i];
    vals2[i - 1] = t;
  }
  sort(vals2, vals2 + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) ans += (vals[i] * vals2[i]);
  cout << ans << "\n";
  return 0;
}
