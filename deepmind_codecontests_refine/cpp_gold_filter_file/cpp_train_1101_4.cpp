#include <bits/stdc++.h>
using namespace std;
int is_bad(int bad[], int m, int num);
int main() {
  int b1, q, l, m;
  cin >> b1 >> q >> l >> m;
  int bad[m];
  for (int i = 0; i < m; ++i) {
    cin >> bad[i];
  }
  if (b1 == 0) {
    if (is_bad(bad, m, b1))
      cout << 0;
    else
      cout << "inf";
    return 0;
  }
  if (q == 0) {
    if (abs(b1) > l)
      cout << 0;
    else {
      if (!is_bad(bad, m, 0))
        cout << "inf";
      else
        cout << 1 - is_bad(bad, m, b1);
    }
    return 0;
  }
  if (abs(q) == 1) {
    if (abs(b1) > l)
      cout << 0;
    else {
      if ((q == 1 && is_bad(bad, m, b1)) ||
          (q == -1 && is_bad(bad, m, b1) && is_bad(bad, m, -b1)))
        cout << 0;
      else
        cout << "inf";
    }
    return 0;
  }
  int count = 0;
  int boarder = l / b1;
  int p = 1;
  while (abs(p) <= abs(boarder)) {
    if (!is_bad(bad, m, b1 * p)) {
      count++;
    }
    p *= q;
  }
  cout << count;
}
int is_bad(int bad[], int m, int num) {
  for (int i = 0; i < m; ++i)
    if (bad[i] == num) return 1;
  return 0;
}
