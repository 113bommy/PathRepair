#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int m = 1;
    for (int j = i; j < n - 1 and a[j] <= a[j + 1]; j++) m++;
    for (int j = i; j > 0 and a[j] <= a[j - 1]; j--) m++;
    ans = max(ans, m);
  }
  cout << ans << endl;
  return 0;
}
