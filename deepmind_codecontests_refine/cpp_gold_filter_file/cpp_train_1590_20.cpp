#include <bits/stdc++.h>
using namespace std;
int n, a[100010];
long long ans, last;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int c = 2;
  for (int i = 0; i < n; i++) {
    ans += abs(a[i] - 1);
  }
  if (n >= 33) {
    cout << ans << endl;
    return 0;
  }
  last = ans;
  ans = 0;
  while (1) {
    for (int i = 0; i < n; i++) ans += abs(a[i] - pow(c, i));
    if (ans > last) {
      cout << last << endl;
      return 0;
    }
    last = ans;
    ans = 0;
    c++;
  }
}
