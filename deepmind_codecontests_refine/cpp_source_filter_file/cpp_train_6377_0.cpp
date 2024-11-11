#include <bits/stdc++.h>
using namespace std;
const int INF = 99999999;
struct O {
  int v, id;
} q[300000];
int p[300000], c[300000];
char S[300000];
int i, j, n, m, temp, ans, tot, len;
bool cmp(O a, O b) { return (a.v < b.v); }
bool YES(char C) {
  if ((C == 'a') || (C == 'e') || (C == 'i') || (C == 'o') || (C == 'u') ||
      (C == 'A') || (C == 'E') || (C == 'I') || (C == 'O') || (C == 'U'))
    return true;
  else
    return false;
}
void insert(int k, int v) {
  for (; k <= len; k += k & (-k)) c[k] = min(c[k], v);
}
int Get(int k) {
  int p = INF;
  for (; k; k -= k & (-k)) p = min(p, c[k]);
  return p;
}
int main() {
  scanf("%s", &S);
  len = strlen(S);
  for (i = 0; i < len; i++) {
    q[i + 1].v = q[i].v + ((YES(S[i])) ? -1 : 2);
    q[i + 1].id = i + 1;
    c[i] = INF;
  }
  c[len] = INF;
  q[0].v = 0;
  q[0].id = 0;
  sort(q, q + len + 1, cmp);
  p[q[0].id] = temp = 1;
  for (i = 1; i <= len; i++) {
    if (q[i].v != q[i - 1].v) temp++;
    p[q[i].id] = temp;
  }
  ans = -INF;
  tot = 0;
  insert(p[0], 0);
  for (i = 1; i <= len; i++) {
    temp = Get(p[i]);
    if (temp != -INF) {
      temp = i - temp;
      if (temp > ans) {
        ans = temp;
        tot = 1;
      } else if (temp == ans)
        tot++;
    }
    insert(p[i], i);
  }
  if (ans != -INF)
    printf("%d %d\n", ans, tot);
  else
    puts("No solution");
  return 0;
}
