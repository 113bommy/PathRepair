#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, i, h, m, a = 0, b = 0, c = 0, cnt = 0;
  cin >> n;
  while (n--) {
    cin >> h >> m;
    if (h == a && m == b) {
      cnt++;
    } else {
      if (cnt > c) {
        c = cnt;
      }
      cnt = 0;
    }
    a = h;
    b = m;
  }
  if (cnt > c) {
    c = cnt;
  }
  if (n == 1)
    cout << 1 << endl;
  else
    cout << c + 1 << endl;
  return 0;
}
