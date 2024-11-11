#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, cnt;
char s[MAXN][10];
int tp[MAXN];
char ostr[MAXN * 20], *op = ostr;
queue<int> st;
queue<int> c[2], v[2];
int check(char *s) {
  int x = 0;
  if (s[0] == '0') return -1;
  for (int i = 0; i < (int)strlen(s); i++) {
    if (s[i] < '0' || s[i] > '9') return -1;
    x = x * 10 + s[i] - 48;
  }
  return x;
}
bool used[MAXN * 10];
int tot;
void move(int x, int y) {
  op += sprintf(op, "move %d %d\n", x, y);
  tot++;
}
int s0;
int main() {
  memset(used, 0, sizeof(used));
  cnt = tot = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    scanf("%d", &tp[i]);
    cnt += tp[i];
  }
  for (int i = 0; i < n; i++) {
    int x = check(s[i]);
    if (x == -1)
      st.push(i);
    else if (x > n) {
      used[x] = 1;
      st.push(i);
    } else if ((x <= cnt) != tp[i]) {
      c[tp[i]].push(x);
      used[x] = 1;
    } else {
      used[x] = 1;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!used[i]) v[i <= cnt].push(i);
  s0 = n + 1;
  while (used[s0]) {
    s0++;
  }
  while (!(c[0].empty() && c[1].empty())) {
    if (!c[0].empty() && !v[0].empty()) {
      int x = c[0].front(), y = v[0].front();
      c[0].pop();
      v[0].pop();
      move(x, y);
      v[1].push(x);
    } else if (!c[1].empty() && !v[1].empty()) {
      int x = c[1].front(), y = v[1].front();
      c[1].pop();
      v[1].pop();
      move(x, y);
      v[0].push(x);
    } else {
      int x = c[0].front();
      c[0].pop();
      move(x, s0);
      v[1].push(x);
      st.push(n);
      sprintf(s[n], "%d", s0);
      tp[n] = 0;
    }
  }
  while (!st.empty()) {
    int x = st.front();
    st.pop();
    op += sprintf(op, "move %s %d\n", s[x], v[tp[x]].front());
    v[tp[x]].pop();
    tot++;
  }
  printf("%d\n%s\n", tot, ostr);
  return 0;
}
