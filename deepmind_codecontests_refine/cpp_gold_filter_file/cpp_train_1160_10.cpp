#include <bits/stdc++.h>
using namespace std;
long long a[100010];
int main() {
  long long ans = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) ans += (a[i - 1] - a[i]) * a[i];
    if (a[i] > a[i - 1]) ans += (a[i] - a[i - 1]) * (n - a[i] + 1);
  }
  ans += a[0] * (n - a[0] + 1);
  cout << ans << endl;
}
