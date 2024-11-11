#include <bits/stdc++.h>
using namespace std;
int diri[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dirj[] = {0, 1, 0, -1, 1, 1, -1, -1};
int compare(double d1, double d2) {
  if (fabs(d1 - d2) < 1e-9) return 0;
  if (d1 < d2) return -1;
  return 1;
}
int main() {
  string a, b;
  cin >> a >> b;
  int c1 = 0, c2 = 0;
  for (int i = 0; i < (int)a.size(); i++) c1 += (a[i] == '1');
  for (int i = 0; i < (int)b.size(); i++) c2 += (b[i] == '1');
  if (c1 >= c2 || ((c1 % 2 == 1) && c1 + 1 == c2))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
