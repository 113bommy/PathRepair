#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  int bx, by, bz;
  vector<int> wtf(7);
  cin >> x >> y >> z;
  cin >> bx >> by >> bz;
  for (int i = 1; i <= 6; i++) cin >> wtf[i];
  int c[7] = {
      0,
  };
  if (y < 0)
    c[1] = 1;
  else if (y > by)
    c[2] = 1;
  if (z < 0)
    c[3] = 1;
  else if (z > by)
    c[4] = 1;
  if (x < 0)
    c[5] = 1;
  else if (x > bx)
    c[6] = 1;
  int res = 0;
  for (int i = 1; i <= 6; i++) res += c[i] * wtf[i];
  cout << res << endl;
  return 0;
}
