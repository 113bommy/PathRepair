#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 1e6 + 6, OO = 0x3f3f3f3f;
int main() {
  int a, b;
  cin >> a >> b;
  int x = a, y = b;
  long long cnt1 = 0, cnt2 = 0;
  while (1) {
    if (x < y) {
      x += a;
      cnt1++;
    } else if (y < x) {
      y += b;
      cnt2++;
    } else
      break;
  }
  if (cnt1 == cnt2 || abs(cnt1 - cnt2) == 1)
    cout << "equal" << endl;
  else if (cnt1 > cnt2)
    cout << "Dasha" << endl;
  else
    cout << "Masha" << endl;
  return 0;
}
