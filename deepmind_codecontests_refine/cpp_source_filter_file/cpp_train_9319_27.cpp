#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  long long ans = 0, temp = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      long long ans1 = 0, ans2 = 0;
      for (int k = i; k <= j; k++) {
        ans1 |= a[k];
        ans2 |= b[k];
      }
      temp = ans1 + ans2;
      ans = max(ans, temp);
    }
  }
  cout << ans << endl;
  return 0;
}
