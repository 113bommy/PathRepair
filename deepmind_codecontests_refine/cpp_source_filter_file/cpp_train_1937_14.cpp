#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int ans = 0;
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (long long int i = 0; i < n; i++)
    if (a[i] == a[2]) ans++;
  if (a[2] == a[0])
    ans = ans * (ans - 1) * (ans - 2) / 6;
  else if (a[2] == a[1])
    ans = ans * (ans - 1) / 2;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
