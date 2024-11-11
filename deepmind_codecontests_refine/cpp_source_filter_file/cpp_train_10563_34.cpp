#include <bits/stdc++.h>
using namespace std;
string a[3005], ans[3005];
int main() {
  int n, m;
  string s;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> s;
    int na = a[i].length();
    int ns = s.length();
    if (na <= ns) {
      ans[i] = a[i];
    } else {
      ans[i] = s;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (a[j] == s) {
        cout << ans[j] << " ";
        break;
      }
    }
  }
  return 0;
}
