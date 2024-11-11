#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000006;
const long long MOD = 1000000007;
int n, a[MAXN], b[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  n = unique(a, a + n) - a;
  a[n] = MAXN;
  for (int i = 0; i < n; i++) {
    for (int j = a[i]; j < a[i + 1]; j++) {
      b[j] = a[i];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = a[i]; j < MAXN; j += a[i]) {
      int mx = b[j - 1];
      if (mx >= a[i]) {
        ans = max(mx % a[i], ans);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
