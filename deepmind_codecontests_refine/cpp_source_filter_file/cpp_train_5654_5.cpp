#include <bits/stdc++.h>
using namespace std;
int n, a, b, t[200], i, m;
int main() {
  scanf("%d%d%d", &n, &a, &b);
  t[0] = 1;
  int sum = 1;
  for (i = 0; i < b; ++i) {
    t[1 + i] = sum + 1;
    sum += t[i + 1];
  }
  bool yes = false;
  if (b == 0) {
    b = 1;
    t[b] = 1;
    yes = true;
  }
  for (i = 0; i < a; ++i) t[b + i + 1] = t[b] + i + 1;
  for (i = b + a + 1; i < n; ++i) t[i] = 1;
  bool ok = true;
  b -= yes;
  sum = t[0];
  m = t[0];
  int x = 0, y = 0;
  for (i = 1; i < n; ++i) {
    if (t[i] > 50000) ok = false;
    if (t[i] > sum) {
      x++;
    } else if (t[i] > m)
      y++;
    sum += t[i];
    m = max(m, t[i]);
  }
  if (x != b && y != a) ok = false;
  if (!ok)
    puts("-1");
  else
    for (i = 0; i < n; ++i) cout << t[i] << " ";
  return 0;
}
