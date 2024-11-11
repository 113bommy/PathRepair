#include <bits/stdc++.h>
using namespace std;
void solve() {
  int b, p, f;
  int h, c;
  int result = 0;
  cin >> b >> p >> f >> h >> c;
  if (h > c) {
    int all_burgers = min(p, b / 2);
    result += all_burgers * h;
    p = p - all_burgers;
    b = b - all_burgers * 2;
    int all_chickecns = min(f, b / 2);
    all_chickecns = max(0, all_chickecns);
    result += all_chickecns * c;
  } else if (h == c) {
    p += f;
    int num = min(p, b / 2);
    result = num * h;
  } else {
    int all_chickecns = min(f, b / 2);
    result += all_chickecns * c;
    f = f - all_chickecns;
    b = b - all_chickecns * 2;
    int all_burgers = min(p, b / 2);
    all_burgers = max(0, all_burgers);
    result += all_burgers * h;
  }
  cout << result << endl;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
