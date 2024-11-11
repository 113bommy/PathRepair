#include <bits/stdc++.h>
using namespace std;
int main() {
  bool flag1 = false;
  vector<int> a;
  int h;
  cin >> h;
  a.resize(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  int m = *max_element(a.begin(), a.end());
  int n = *min_element(a.begin(), a.end());
  if (m - n == 0 || m - n == 1) {
    cout << "YES";
    flag1 = true;
  } else if ((m - n) % 2) {
    for (int i = 0; i < h; i++) {
      int x = (m - n);
      if (a[i] == m || a[i] + x == m) {
        continue;
      } else if (a[i] == n || a[i] - x == n) {
        continue;
      } else {
        cout << "NO";
        flag1 = true;
        break;
      }
    }
  } else {
    int x = (m + n) / 2;
    int y = m - x;
    for (int i = 0; i < h; i++) {
      if (a[i] == x || a[i] - y == x || a[i] + y == x) {
        continue;
      } else {
        cout << "NO";
        flag1 = true;
        break;
      }
    }
  }
  if (!flag1) cout << "YES";
  return 0;
}
