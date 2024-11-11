#include <bits/stdc++.h>
char ch[6000];
int up[6000], down[6000], left[6000], right[6000], vis[6000], st[6000];
char op[6000];
void add(int t) {
  if (up[t] >= 0) down[up[t]] = t;
  if (down[t] >= 0) up[down[t]] = t;
  if (left[t] >= 0) right[left[t]] = t;
  if (right[t] >= 0) left[right[t]] = t;
}
void del(int t) {
  if (up[t] >= 0) down[up[t]] = down[t];
  if (down[t] >= 0) up[down[t]] = up[t];
  if (left[t] >= 0) right[left[t]] = right[t];
  if (right[t] >= 0) left[right[t]] = left[t];
}
int dfs(int t) {
  if (ch[t] == 'U' && up[t] < 0) return 1;
  if (ch[t] == 'D' && down[t] < 0) return 1;
  if (ch[t] == 'L' && left[t] < 0) return 1;
  if (ch[t] == 'R' && right[t] < 0) return 1;
  int next;
  if (ch[t] == 'U') next = up[t];
  if (ch[t] == 'D') next = down[t];
  if (ch[t] == 'L') next = left[t];
  if (ch[t] == 'R') next = right[t];
  del(t);
  next = dfs(next) + 1;
  add(t);
  return next;
}
int main() {
  int n, m, num = 0;
  scanf("%d %d", &n, &m);
  getchar();
  char *p = ch;
  for (int i = 0; i < m; i++) vis[i] = -1;
  for (int i = 0; i < n * m; i++) up[i] = down[i] = right[i] = left[i] = -1;
  for (int i = 0; i < n; i++) {
    gets(ch + i * m);
    for (int j = 0, pre = -1; j < m; j++)
      if (*(p++) != '.') {
        int cur = i * m + j;
        if (vis[j] >= 0) up[cur] = vis[j] * m + j, down[vis[j] * m + j] = cur;
        vis[j] = i;
        if (pre >= 0) left[cur] = i * m + pre, right[i * m + pre] = cur;
        pre = j;
        st[num++] = cur;
      }
  }
  int ans = 0, ans_n = 0;
  for (int i = 0; i < num; i++) {
    int tmp = dfs(st[i]);
    if (tmp > ans)
      ans = tmp, ans_n = 1;
    else if (tmp == ans)
      ans_n++;
  }
  printf("%d %d\n", ans + 1, ans_n);
}
