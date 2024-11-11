#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[0]) ans++;
    if (a[i] == a[n - 1]) ans--;
  }
  cout << ans << endl;
}
