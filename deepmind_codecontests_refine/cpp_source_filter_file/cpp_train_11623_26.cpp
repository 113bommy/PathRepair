#include <bits/stdc++.h>
using namespace std;
int main() {
  int pb, mb, bb, m;
  cin >> pb >> mb >> bb >> m;
  int s1 = 2 * pb;
  int temp = 2 * m;
  if (2 * m > s1) {
    cout << -1 << endl;
    return 0;
  }
  int s2 = 2 * mb;
  if (2 * m > s2) {
    cout << -1 << endl;
    return 0;
  }
  int s3 = 2 * bb, c = 0;
  for (int i = bb; i <= s3; i++) {
    if (m <= i && temp >= i) {
      s3 = i;
      c = 1;
      break;
    }
  }
  if (c == 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;
  return 0;
}
