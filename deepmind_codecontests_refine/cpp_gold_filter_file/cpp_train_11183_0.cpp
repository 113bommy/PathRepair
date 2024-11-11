#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  sort(a, a + n);
  int t;
  cin >> t;
  int ans = 1;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (a[j] - a[i] <= t) ans = max(ans, j - i + 1);
  cout << ans << endl;
}
