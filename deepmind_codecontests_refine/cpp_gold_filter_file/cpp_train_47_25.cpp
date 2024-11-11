#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int prevx, prevh, x, h, nextx, nexth;
  cin >> prevx >> prevh;
  if (n == 1) {
    cout << "1";
    return 0;
  }
  int count = 1;
  int l = 1, r = 0;
  cin >> x >> h;
  if (n == 2) {
    cout << "2";
    return 0;
  }
  n = n - 2;
  while (n--) {
    cin >> nextx >> nexth;
    if (h < x - prevx && r != 1) {
      count++;
    } else if (h + prevh < x - prevx) {
      count++;
      r = 0;
    } else if (h < nextx - x) {
      count++;
      r = 1;
    } else {
      r = 0;
    }
    prevx = x;
    prevh = h;
    x = nextx;
    h = nexth;
  }
  count++;
  cout << count;
}
