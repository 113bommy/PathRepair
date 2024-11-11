#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long int n;
  cin >> n;
  long int a[n], b[n], suma = 0, sumb = 0;
  for (long int i = 0; i < n; i++) {
    cin >> a[i];
    cin >> b[i];
    suma += a[i];
    sumb += b[i];
  }
  vector<pair<long int, long int>> v;
  bool flag = true;
  for (long int i = 0; i < n; i++) {
    v.push_back(make_pair(a[i], b[i]));
  }
  if (suma % 2 == 0 && sumb % 2 == 0) {
    cout << 0 << endl;
  } else if (suma % 2 != 0 && sumb % 2 != 0) {
    for (auto x : v) {
      if ((x.first % 2 == 0 && x.second % 2 != 0) ||
          (x.first % 2 != 0 && x.second % 2 == 0)) {
        cout << 1 << endl;
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << -1 << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
