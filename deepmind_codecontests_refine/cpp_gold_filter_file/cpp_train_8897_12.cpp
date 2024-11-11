#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 7;
const int MAXT = 24 * 3600 + 7;
int n, m, t, usr[MAXN], req[MAXN], uid[MAXN];
void solve() {
  int l = 0, r = 0, tot = 0, M = 0;
  for (int i = (0); i < (n); ++i) {
    while (l < r && req[i] - req[usr[l]] >= t) ++l;
    if (r - l < m) {
      uid[i] = tot++, usr[r++] = i;
    } else {
      uid[i] = uid[usr[r - 1]], usr[r - 1] = i;
    }
    M = max(M, r - l);
  }
  if (M < m) {
    puts("No solution");
    return;
  }
  printf("%d\n", tot);
  for (int i = (0); i < (n); ++i) printf("%d\n", uid[i] + 1);
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = (0); i < (n); ++i) {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    req[i] = h * 3600 + m * 60 + s;
  }
  solve();
  return 0;
}
