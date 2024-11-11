#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int ans = 0;
  int j;
  for (int i = 0; i < n;) {
    j = i + 1;
    ans += a[j] - a[i];
    i = i + 2;
  }
  cout << ans << endl;
  return 0;
}
