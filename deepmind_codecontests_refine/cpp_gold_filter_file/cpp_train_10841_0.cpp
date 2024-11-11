#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MAXN = 3e5 + 19;
long long n, a[MAXN];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans;
  for (int i = 1; i < n; i++)
    if (a[i] != a[0]) ans = i;
  for (int i = 0; i < n - 1; i++)
    if (a[i] != a[n - 1]) ans = max(n - 1 - i, ans);
  cout << ans << endl;
  return 0;
}
