#include <bits/stdc++.h>
using namespace std;
char x, y;
int i, j;
int p, t, ans;
int main() {
  cin >> x >> y;
  i = x - 'a' + 1;
  j = y - '0';
  p = i + 1;
  t = j;
  if (p >= 1 && p <= 8 && t >= 1 && t <= 8) ++ans;
  p = i - 1;
  t = j;
  if (p >= 1 && p <= 8 && t >= 1 && t <= 8) ++ans;
  p = i;
  t = j + 1;
  if (p >= 1 && p <= 8 && t >= 1 && t <= 8) ++ans;
  p = i;
  t = j - 1;
  if (p >= 1 && p <= 8 && t >= 1 && t <= 8) ++ans;
  p = i + 1;
  t = j + 1;
  if (p >= 1 && p <= 8 && t >= 1 && t <= 8) ++ans;
  p = i + 1;
  t = j - 1;
  if (p >= 1 && p <= 8 && t >= 1 && t <= 8) ++ans;
  p = i - 1;
  t = j + 1;
  if (p >= 1 && p <= 8 && t >= 1 && t <= 8) ++ans;
  p = i - 1;
  t = j - 1;
  if (p >= 1 && p <= 8 && t >= 1 && t <= 8) ++ans;
  cout << ans << endl;
}
