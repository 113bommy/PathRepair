#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, l = 0, r = 0, c = 0;
  int x1[10100][2];
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> x1[i][0] >> x1[i][1];
    if (x1[i][0] == 1) l++;
    if (x1[i][1] == 0) r++;
  }
  if (l == x) l = 0;
  if (r == x) r = 0;
  if (l <= x / 2)
    c = l;
  else
    c = x - l;
  if (r <= x / 2)
    c += r;
  else
    c += x - r;
  cout << c << "\n";
}
