#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int MX = 99999 + 10, inf = 1e9 + 7;
int fr[10];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i > k; i--)
    if (a[i] != a[k - 1]) puts("-1"), exit(0);
  int ans = k;
  while (ans > 0 and a[ans - 1] == a[k - 1]) ans--;
  cout << ans << '\n';
  return 0;
}
