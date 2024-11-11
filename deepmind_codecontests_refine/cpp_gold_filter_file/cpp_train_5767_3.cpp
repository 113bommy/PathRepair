#include <bits/stdc++.h>
using namespace std;
int dir[4] = {0, 0, 0, 0};
long long int t, sx, sy, ex, ey;
long long int x, y;
bool p1 = false, p2 = false;
int sum1 = 0, sum2 = 0;
char s[100010];
char c;
int main() {
  cin >> t >> sx >> sy >> ex >> ey;
  x = ex - sx;
  y = ey - sy;
  for (int i = 0; i < t; i++) {
    cin >> c;
    s[i] = c;
    if (c == 'N')
      dir[0]++;
    else if (c == 'E')
      dir[1]++;
    else if (c == 'S')
      dir[2]++;
    else
      dir[3]++;
  }
  if (x == 0)
    p1 = true;
  else if (x > 0 && dir[1] < x) {
    cout << "-1";
    return 0;
  } else if (x > 0 && dir[1] >= x)
    p1 = true;
  else if (x < 0 && dir[3] < abs(x)) {
    cout << "-1";
    return 0;
  } else if (x < 0 && dir[3] >= abs(x))
    p1 = true;
  if (y == 0)
    p2 = true;
  else if (y > 0 && dir[0] < y) {
    cout << "-1";
    return 0;
  } else if (y > 0 && dir[0] >= y)
    p2 = true;
  else if (y < 0 && dir[2] < abs(y)) {
    cout << "-1";
    return 0;
  } else if (y < 0 && dir[2] >= abs(y))
    p2 = true;
  if (!p1 || !p2) {
    cout << "-1";
    return 0;
  } else {
    for (int i = 0; i < t; i++) {
      if (s[i] == 'E' && x > 0)
        sum1++;
      else if (s[i] == 'W' && x < 0)
        sum1++;
      else if (s[i] == 'N' && y > 0)
        sum2++;
      else if (s[i] == 'S' && y < 0)
        sum2++;
      if (sum1 >= abs(x) && sum2 >= abs(y)) {
        cout << i + 1;
        return 0;
      }
    }
  }
  return 0;
}
