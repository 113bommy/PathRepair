#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int k, n, m, Q;
int s1[N], s2[N], f1[N], f2[N];
int l1, r1, l2, r2;
char s[N], t[N];
bool Solve(int l1, int r1, int l2, int r2) {
  int x = s1[r1] - s1[l1 - 1], y = s2[r2] - s2[l2 - 1];
  if (x > y || ((y - x) & 1)) return 0;
  int len1 = min(f1[r1], r1 - l1 + 1), len2 = min(f2[r2], r2 - l2 + 1);
  if (x == y) {
    if (len1 < len2) return 0;
    return !((len1 - len2) % 3);
  }
  if (!x) return len1 > len2;
  return len1 >= len2;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  scanf("%s", t + 1);
  m = strlen(t + 1);
  for (int i = 1; i <= n; i++)
    s1[i] = s1[i - 1] + (s[i] != 'A'), f1[i] = s[i] == 'A' ? f1[i - 1] + 1 : 0;
  for (int i = 1; i <= m; i++)
    s2[i] = s2[i - 1] + (t[i] != 'A'), f2[i] = t[i] == 'A' ? f2[i - 1] + 1 : 0;
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d", &l1);
    scanf("%d", &r1);
    scanf("%d", &l2);
    scanf("%d", &r2);
    putchar(Solve(l1, r1, l2, r2) ? '1' : '0');
  }
  return 0;
}
