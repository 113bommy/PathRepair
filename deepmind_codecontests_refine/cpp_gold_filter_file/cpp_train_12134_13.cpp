#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int ans = 0;
  long long int m = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] <= a[i - 1]) {
      m = max(ans, m);
      ans = 0;
    } else {
      ans++;
    }
  }
  ans = max(ans, m);
  cout << ans + 1;
}
