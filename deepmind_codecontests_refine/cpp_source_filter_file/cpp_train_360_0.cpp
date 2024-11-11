#include <bits/stdc++.h>
using namespace std;
char s[200200], t[20020];
bool solve(int l, int r, int L, int R) {
  bool f = 1;
  for (int i = l, j = L; i < r && j < R && f; i++, j++)
    if (s[i] != t[j]) f = 0;
  if (f) return 1;
  int len = r - l;
  if (len % 2 == 0) {
    int m = (l + r) >> 1;
    int M = (L + R) >> 1;
    if (solve(l, m, L, M) && solve(m, r, M, R)) return 1;
    if (solve(l, m, M, R) && solve(m, r, L, M)) return 1;
  }
  return 0;
}
int main() {
  scanf("%s%s", s, t);
  int n = strlen(s);
  if (solve(0, n, 0, n))
    puts("YES");
  else
    puts("NO");
  return 0;
}
