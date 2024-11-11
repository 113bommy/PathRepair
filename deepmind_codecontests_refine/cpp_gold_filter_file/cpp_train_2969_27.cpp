#include <bits/stdc++.h>
using namespace std;
int month[] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ar[] = {4, 5, 6, 7, 1, 2, 3};
int main() {
  int i, j, k, q, x;
  string a, s;
  cin >> x >> a >> s;
  if (s[0] == 'm') {
    int cnt = 0;
    for (i = 1; i <= 12; i++) {
      if (x <= month[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
  }
  x--;
  int bg = ar[x];
  int cnt = 0, d;
  int rn = -1;
  for (i = 1; i <= 12; i++) {
    if (i == 1)
      d = bg;
    else
      d = 1;
    for (d; d <= month[i]; d++) {
      rn++;
      if (rn % 7 == 0) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
