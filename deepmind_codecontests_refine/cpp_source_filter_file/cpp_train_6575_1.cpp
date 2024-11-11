#include <bits/stdc++.h>
using namespace std;
long long const INF = 1e18;
long long s[300100], a[300100];
int n, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  s[n + 1] = 0;
  for (int i = n; i >= 1; i--) s[i] = s[i + 1] + a[i];
  s[0] = s[1];
  sort(s + 1, s + n + 1);
  long long res = 0;
  for (int i = n; i >= n - k + 2; i--) res = res + s[i];
  res += s[0];
  cout << res << endl;
  return 0;
}
