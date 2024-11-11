#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4000005, tt = 51123987;
int n, m, all, ans, p[MAXN], st[MAXN];
char s[MAXN], ss[MAXN];
int Add(int x, int y) { return x + y < tt ? x + y : x + y - tt; }
int Sub(int x, int y) { return x - y >= 0 ? x - y : x - y + tt; }
void Manachar() {
  for (int i = (1); i <= (n); i++) ss[++m] = '*', ss[++m] = s[i];
  ss[++m] = '*';
  int id = 0, Max = 0;
  for (int i = (1); i <= (m); i++) {
    p[i] = (Max > i ? min(Max - i, p[2 * id - i]) : 1);
    while (i - p[i] >= 1 && i + p[i] <= m && ss[i - p[i]] == ss[i + p[i]])
      p[i]++;
    if (i + p[i] > Max) id = i, Max = i + p[i];
  }
}
void Getans() {
  for (int i = (1); i <= (m); i++)
    st[(i - p[i] + 1) / 2 + 1]++, st[i / 2 + 1]--;
  for (int i = (1); i <= (n); i++) st[i] += st[i - 1];
  st[n + 1] = 0;
  for (int i = (n); i >= (1); i--) st[i] = Add(st[i], st[i + 1]);
  for (int i = (n); i >= (1); i--) st[i] = Add(st[i], st[i + 1]);
  for (int i = (1); i <= (m); i++) {
    all = Add(all, p[i] / 2);
    ans = Add(ans, st[(i + 1) / 2 + 1]);
    ans = Sub(ans, st[(i + p[i] - 1) / 2 + 2]);
  }
  all = (long long)all * (all - 1) / 2;
  ans = Sub(all, ans);
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  Manachar();
  Getans();
  printf("%d\n", ans);
  return 0;
}
