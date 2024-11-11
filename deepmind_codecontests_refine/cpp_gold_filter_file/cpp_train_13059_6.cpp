#include <bits/stdc++.h>
long l[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}, d[700001] = {0},
     du[700001] = {0}, num[1005][1005] = {0}, head[700001] = {0},
     e[4000001] = {0}, next[4000001] = {0}, stack[700001] = {0},
     dfn[700001] = {0}, low[700001] = {0}, c[700001] = {0}, opp[700001] = {0},
     e2[4000001] = {0}, next2[4000001] = {0}, head2[700001] = {0},
     ans[700001] = {0};
char out[1005][1005] = {0}, map[1005][1005] = {0};
long totm = 0, top = 0, color = 0, tot = 0;
void add(long a, long b) {
  e[++totm] = b;
  next[totm] = head[a];
  head[a] = totm;
}
void add2(long a, long b) {
  e2[++totm] = b;
  next2[totm] = head2[a];
  head2[a] = totm;
  du[b]++;
}
void tarjan(long now) {
  long i;
  dfn[now] = low[now] = ++tot;
  stack[++top] = now;
  for (i = head[now]; i; i = next[i])
    if (!dfn[e[i]]) {
      tarjan(e[i]);
      low[now] = ((low[now]) < (low[e[i]]) ? (low[now]) : (low[e[i]]));
    } else if (!c[e[i]])
      low[now] = ((low[now]) < (dfn[e[i]]) ? (low[now]) : (dfn[e[i]]));
  if (dfn[now] == low[now]) {
    color++;
    do c[stack[top--]] = color;
    while (stack[top + 1] != now);
  }
}
int main() {
  long i, j, k, a, b, n, m, st = 1, en = 0, nb = 0, nw = 0, now;
  scanf("%ld%ld\n", &n, &m);
  for (i = 1; i <= n; i++) {
    gets(map[i] + 1);
    for (j = 1; j <= m; j++) {
      nb += (map[i][j] == 'b');
      nw += (map[i][j] == 'w');
      if (map[i][j] == 'b') num[i][j] = nb;
    }
  }
  if (nb * 2 != nw) {
    puts("NO");
    goto out;
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (num[i][j]) {
        if (map[i - 1][j] != 'w' || map[i + 1][j] != 'w')
          add(num[i][j] * 2 - 1, num[i][j] * 2);
        if (map[i][j - 1] != 'w' || map[i][j + 1] != 'w')
          add(num[i][j] * 2, num[i][j] * 2 - 1);
        if (map[i - 1][j + 1] == 'b') {
          add(num[i][j] * 2, num[i - 1][j + 1] * 2);
          add(num[i][j] * 2 - 1, num[i - 1][j + 1] * 2 - 1);
          add(num[i - 1][j + 1] * 2, num[i][j] * 2);
          add(num[i - 1][j + 1] * 2 - 1, num[i][j] * 2 - 1);
        }
        if (map[i][j + 2] == 'b') {
          add(num[i][j] * 2, num[i][j + 2] * 2 - 1);
          add(num[i][j + 2] * 2, num[i][j] * 2 - 1);
        }
        if (map[i + 1][j + 1] == 'b') {
          add(num[i][j] * 2, num[i + 1][j + 1] * 2);
          add(num[i][j] * 2 - 1, num[i + 1][j + 1] * 2 - 1);
          add(num[i + 1][j + 1] * 2, num[i][j] * 2);
          add(num[i + 1][j + 1] * 2 - 1, num[i][j] * 2 - 1);
        }
        if (map[i + 2][j] == 'b') {
          add(num[i][j] * 2 - 1, num[i + 2][j] * 2);
          add(num[i + 2][j] * 2 - 1, num[i][j] * 2);
        }
      }
  for (i = 1; i <= 2 * nb; i++)
    if (!dfn[i]) tarjan(i);
  for (i = 1; i <= 2 * nb && c[i] != c[((i - 1) ^ 1) + 1]; i++) {
    opp[c[i]] = c[((i - 1) ^ 1) + 1];
    opp[c[((i - 1) ^ 1) + 1]] = c[i];
  }
  if (i <= 2 * nb) {
    puts("NO");
    goto out;
  }
  puts("YES");
  totm = 0;
  for (i = 1; i <= 2 * nb; i++)
    for (j = head[i]; j; j = next[j])
      if (c[i] != c[e[j]]) add2(c[e[j]], c[i]);
  for (i = 1; i <= color; i++)
    if (!du[i]) {
      d[++en] = i;
      ans[i] = 1;
      ans[opp[i]] = 2;
    }
  while (st <= en) {
    now = d[st++];
    for (i = head2[now]; i; i = next2[i])
      if (!ans[e2[i]]) {
        du[e2[i]]--;
        if (!du[e2[i]]) {
          ans[e2[i]] = 1;
          ans[opp[e2[i]]] = 2;
          d[++en] = e2[i];
        }
      }
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (num[i][j])
        if (ans[c[num[i][j] * 2 - 1]] == 1) {
          for (k = 0; k <= 4; k++) {
            for (a = -1; a <= 1; a++)
              for (b = 0; b <= 3; b++)
                if (out[i + a + l[b][0]][j + l[b][1]] == 'a' + k) goto no;
          no:
            if (a == 2) break;
          }
          out[i - 1][j] = out[i][j] = out[i + 1][j] = 'a' + k;
        } else {
          for (k = 0; k <= 4; k++) {
            for (a = -1; a <= 1; a++)
              for (b = 0; b <= 3; b++)
                if (out[i + l[b][0]][j + a + l[b][1]] == 'a' + k) goto no2;
          no2:
            if (a == 2) break;
          }
          out[i][j - 1] = out[i][j] = out[i][j + 1] = 'a' + k;
        }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) putchar(out[i][j] ? out[i][j] : '.');
    puts("");
  }
out:
  return 0;
}
