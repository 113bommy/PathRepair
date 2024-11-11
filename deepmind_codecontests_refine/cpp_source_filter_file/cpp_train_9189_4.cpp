#include <bits/stdc++.h>
using namespace std;
int AAbs(int x) {
  if (x >= 0) {
    return x;
  } else {
    return -x;
  }
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x1, y1, x2, y2;
    int count = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    count = AAbs(x2 - x1) + AAbs(y2 - y1);
    if (x1 == x2 || y1 == y2) {
      count += 0;
    } else {
      count = 2;
    }
    cout << count << endl;
  }
  return 0;
}
