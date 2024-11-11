#include <bits/stdc++.h>
using namespace std;
bool a(int d1, int m1, int y1, int d2, int m2, int y2) {
  if (y1 - y2 > 18)
    return 1;
  else if (y1 - y2 == 18) {
    if (m1 > m2)
      return 1;
    else if (m1 == m2) {
      if (d1 == d2) return 1;
    }
  }
  return 0;
}
bool b(int d, int m, int y) {
  if (m < 1 || m > 12) return 0;
  if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) &&
      d > 31)
    return 0;
  if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return 0;
  if (m == 2) {
    if (y % 4 == 0 && d > 29) return 0;
    if (y % 4 && d > 28) return 0;
  }
  return 1;
}
int main() {
  int t1[3], t2[3];
  bool flag = 0;
  scanf("%d.%d.%d", &t1[0], &t1[1], &t1[2]);
  scanf("%d.%d.%d", &t2[0], &t2[1], &t2[2]);
  sort(t2, t2 + 3);
  do {
    if (b(t1[0], t1[1], t1[2]) && b(t2[0], t2[1], t2[2])) {
      if (a(t1[0], t1[1], t1[2], t2[0], t2[1], t2[2])) {
        flag = 1;
      }
    }
  } while (next_permutation(t2, t2 + 3));
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
