#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, t = 0, f = 0, h = 0;
  cin >> n;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == 25) {
      t++;
    } else if (a == 50) {
      if (t < 1) {
        flag = false;
        break;
      }
      t--;
      f++;
    } else {
      if (f >= 1 && t >= 1) {
        t--;
        f--;
        h++;
      } else if (t >= 3) {
        t -= 3;
        h++;
      } else {
        flag = false;
        break;
      }
    }
  }
  if (flag) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
