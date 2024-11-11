#include <bits/stdc++.h>
using namespace std;
int a[200010];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int mi = a[1];
  long long d = 0;
  bool flag = true;
  for (int i = 2; i <= n; i++) {
    a[i] -= d;
    if (a[i] < 0)
      flag = false;
    else {
      if (a[i] <= mi)
        mi = a[i];
      else {
        d += (a[i] - mi);
      }
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
