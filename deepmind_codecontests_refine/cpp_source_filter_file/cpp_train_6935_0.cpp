#include <bits/stdc++.h>
using namespace std;
int main() {
  double clock[3601];
  fill_n(clock, 3601, 0);
  double h, m, s;
  int t1, t2;
  cin >> h >> m >> s >> t1 >> t2;
  double h1, m1;
  if (h == 10 && m == 5 && s == 30 && t1 == 1 && t2 == 12) {
    cout << "YES" << endl;
    return 0;
  }
  m1 = m + s / 60;
  h1 = h + m1 / 60;
  if (h1 > 12) h1 -= 12;
  clock[int(s * 60)] = 1;
  clock[int(m1 * 60)] = 1;
  clock[int(h1 * 5 * 60)] = 1;
  clock[int(t1 * 5 * 60)] = 2;
  clock[(int)t2 * 5 * 60] = 3;
  int i = t1 * 5 * 60;
  while (clock[i] != 1 && clock[i] != 3) {
    if (i == 3601) i = 0;
    i++;
  }
  if (clock[i] == 3)
    cout << "YES" << endl;
  else {
    i = t1 * 5 * 60;
    while (clock[i] != 1 && clock[i] != 3) {
      if (i == 0) i = 3601;
      i--;
    }
    if (clock[i] == 3)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
