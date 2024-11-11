#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, cnt = 2, ans = 2;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i += 1) cin >> v[i];
  if (n < 3)
    cout << n << endl;
  else {
    for (int i = 2; i < n; i += 1) {
      if (v[i] == v[i - 1] + v[i - 2]) {
        cnt++;
      } else {
        cnt = 0;
      }
      ans = max(ans, cnt);
    }
    cout << ans << endl;
  }
}
