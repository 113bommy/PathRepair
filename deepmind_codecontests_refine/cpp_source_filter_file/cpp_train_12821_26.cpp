#include <bits/stdc++.h>
using namespace std;
int n, i, a, r[1008], c[1008], p[1008], q[1008];
int main() {
  for (scanf("%d", &n); i < n; ++i, scanf("%d", p + i), q[p[i]] = i)
    ;
  for (i = n + 1; --i; p[q[p[i]] = q[i]] = r[i] = p[i])
    ;
  for (i = 0; i < n; ++i, scanf("%d", p + i), q[p[i]] = i)
    ;
  for (i = n + 1; --i; p[q[p[i]] = q[i]] = c[i] = p[i])
    ;
  for (a = n, i = n + 1; --i; a -= (i == r[i] && i == c[i]))
    ;
  for (printf("%d\n", a), i = n + 1; --i;
       (i == r[i] && i == c[i]) ? 0 : printf("%d%d%d%d\n", r[i], i, i, c[i]))
    ;
  exit(0);
}
