#include <bits/stdc++.h>
using namespace std;
long long int a[100010];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long int s = 0LL;
  for (int i = 1; i <= n; i++) s += a[i];
  long long int ans = 1LL;
  for (int i = 1; i <= n; i++) ans = max(ans, a[i] - (s - a[i]));
  cout << ans << endl;
  return 0;
}
