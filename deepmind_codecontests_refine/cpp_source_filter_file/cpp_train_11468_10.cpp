#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  int up = -1, down = 200001;
  string ans = "";
  int n, i, fl = 0;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    if (a[i] > up && a[i] < down) {
      if (a[i] < a[i + 1])
        up = a[i], ans += "0";
      else
        down = a[i], ans += "1";
    } else if (a[i] > up)
      up = a[i], ans += "0";
    else if (a[i] < down)
      down = a[i], ans += "1";
    else {
      fl = 1;
      break;
    }
  }
  if (fl == 1)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    cout << ans << endl;
  }
}
