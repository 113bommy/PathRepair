#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    v.push_back(value);
  }
  long long int ans = 0;
  int flag;
  if (v[0] >= 0)
    flag = 1;
  else
    flag = 0;
  int m = v[0];
  for (int i = 0; i < n; i++) {
    if (v[i] >= 0) {
      if (flag == 0) {
        flag = 1;
        ans = ans + m;
        m = v[i];
      } else if (flag == 1)
        m = max(m, v[i]);
    } else {
      if (flag == 1) {
        flag = 0;
        ans = ans + m;
        m = v[i];
      } else if (flag == 0)
        m = max(m, v[i]);
    }
  }
  ans = ans + m;
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
