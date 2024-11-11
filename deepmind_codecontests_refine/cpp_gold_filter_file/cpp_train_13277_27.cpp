#include <bits/stdc++.h>
using namespace std;
long long int a[100001];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  long long int ans = 1;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++)
    if (a[i] >= ans) ans++;
  cout << ans << endl;
  return 0;
}
