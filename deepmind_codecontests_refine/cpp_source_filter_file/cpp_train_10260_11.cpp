#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, sgn = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  return x * sgn;
}
const int N = 1e5 + 10;
const int B = 310;
int a[N], f[N], ff[N], tmp[N], n, Q, ans[N];
vector<int> pot;
struct query {
  int l, r, bl, id;
} q[N];
bool operator<(query a, query b) {
  return a.bl ^ b.bl ? a.bl < b.bl : a.bl & 1 ? a.r < b.r : a.r > b.r;
}
void upd(int x, int c) {
  ff[f[x]]--;
  f[x] += c;
  ff[f[x]]++;
}
int getans() {
  static priority_queue<int, vector<int>, greater<int> > q;
  for (int x : pot)
    if (f[x] > B) q.push(x);
  int lst = 0, tot = 0;
  for (int i = 1; i <= B; i++) tmp[i] = ff[i];
  for (int i = 1; i <= B; i++) {
    if (!tmp[i]) continue;
    if (lst) {
      tot += i + lst;
      tmp[i]--;
      if (i + lst <= B)
        tmp[i + lst]++;
      else
        q.push(i + lst);
      lst = 0;
    }
    if (tmp[i] & 1) tmp[i]--, lst = i;
    tot += tmp[i] * i;
    if ((i << 1) > B)
      for (int t = tmp[i] >> 1; t; t--) q.push(i << 1);
    else
      tmp[i << 1] += tmp[i] >> 1;
  }
  if (lst) q.push(lst);
  while (q.size() > 1) {
    int x = q.top();
    q.pop();
    x += q.top();
    q.pop();
    q.push(x);
    tot += x;
  }
  if (q.size()) q.pop();
  return tot;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) f[a[i] = read()]++;
  Q = read();
  for (int i = 1; i <= Q; i++)
    q[i].l = read(), q[i].r = read(), q[i].bl = (q[i].l - 1) / B + 1,
    q[i].id = i;
  sort(q + 1, q + Q + 1);
  for (int i = 1; i <= N - 10; i++)
    if (f[i] > B) pot.push_back(i);
  memset(f, 0, sizeof f);
  ff[0] = N - 10;
  int l = 1, r = 0;
  for (int i = 1; i <= Q; i++) {
    while (r > q[i].r) upd(a[r--], -1);
    while (r < q[i].r) upd(a[++r], 1);
    while (l > q[i].l) upd(a[--l], 1);
    while (l < q[i].l) upd(a[l++], -1);
    ans[q[i].id] = getans();
  }
  for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
  return 0;
}
