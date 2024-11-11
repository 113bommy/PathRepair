#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
const long long oo = 1e18;
const double eps = 1e-11;
int x, y, z;
int xx1, yy1, z1;
int a, b, c;
bool win(int X, int Y, int Z) {
  if (X > 0 && xx1 <= 0) return 1;
  if (X <= 0) return 0;
  if (Y <= z1) return 0;
  if (yy1 <= Z) return 1;
  int cc, bb;
  cc = X / (yy1 - Z);
  bb = xx1 / (Y - z1);
  if (X % (yy1 - Z) != 0) cc++;
  if (xx1 % (Y - z1) != 0) bb++;
  if (cc > bb) return 1;
  return 0;
}
int sol = 1e9;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cin >> x >> y >> z;
  cin >> xx1 >> yy1 >> z1;
  cin >> a >> b >> c;
  for (int i = 0; i <= 1000; i++)
    for (int j = 0; j <= 200; j++)
      for (int k = 0; k <= 200; k++) {
        if (win(x + i, y + j, z + k)) {
          sol = min(sol, i * a + b * j + c * k);
        }
      }
  cout << sol << endl;
}
