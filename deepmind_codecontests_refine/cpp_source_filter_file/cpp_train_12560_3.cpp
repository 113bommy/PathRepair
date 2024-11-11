#include <bits/stdc++.h>
using namespace std;
int w1[100001], w2[100001], r2[100001], r1[100001];
int main() {
  string s, t;
  int q;
  cin >> s >> t;
  scanf("%d", &q);
  for (int i = 1; i <= s.size(); ++i)
    if (s[i - 1] == 'A') {
      r1[i] += 2 + r1[i - 1];
      r2[i] += 1 + r2[i - 1];
    } else
      r1[i] += 1 + r1[i - 1];
  for (int i = 1; i <= t.size(); ++i)
    if (t[i - 1] == 'A') {
      w1[i] += 2 + w1[i - 1];
      w2[i] += 1 + w2[i - 1];
    } else
      w1[i] += 1 + w1[i - 1];
  for (int i = 1; i <= q; ++i) {
    int x, y, u, v, r = 0, w = 0, j1, j2;
    scanf("%d%d%d%d", &x, &y, &u, &v);
    r = r1[y] - r1[x - 1], w = w1[v] - w1[u - 1];
    j1 = min(r2[y], y - x + 1), j2 = min(w2[v], v - u + 1);
    if (r > w || (w - r) % 2 != 0 || j1 < j2)
      printf("0");
    else if (r == w && ((j1 - j2) % 3 != 0))
      printf("0");
    else if (j1 == j2 && r != w && r == 0)
      printf("0");
    else
      printf("1");
  }
  return 0;
}
