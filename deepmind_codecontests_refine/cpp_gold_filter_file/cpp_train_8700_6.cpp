#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int f[maxn], n;
struct struc {
  long long a[maxn];
  int go[19][maxn], nxt[maxn];
  void build(int ty = 0) {
    if (!ty) {
      for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
      for (int i = n; i; i--) a[i] += a[i + 1];
    }
    static map<long long, int> pos;
    pos.clear();
    pos[0] = n + 1;
    for (int i = n; i; i--) nxt[i] = pos[a[i]], pos[a[i]] = i;
  }
} sav[3];
vector<pair<int, int> > up[maxn], dow[maxn];
int c[maxn];
void push(int i, int j, int v) {
  c[max(i, j)] = max(c[max(i, j)], v);
  if (i <= j) up[i].push_back(pair<int, int>(j, v));
  if (j <= i) dow[j].push_back(pair<int, int>(i, v));
}
void trans(int i, int j, int v) {
  push(i + 1, j, v), push(i, j + 1, v);
  if (sav[0].nxt[i]) push(sav[0].nxt[i], j, v + 1);
  if (sav[1].nxt[j]) push(i, sav[1].nxt[j], v + 1);
  if (i == j && sav[2].nxt[i]) push(sav[2].nxt[i], sav[2].nxt[i], v + 1);
}
int main() {
  scanf("%d", &n);
  sav[0].build(), sav[1].build();
  for (int i = 1; i <= n; i++) sav[2].a[i] = sav[0].a[i] + sav[1].a[i];
  sav[2].build(1);
  for (int i = 1; i <= n; i++) {
    int go_up = (1 << 30), go_dow = (1 << 30);
    trans(i, i, c[i]);
    for (auto p : up[i])
      if (p.second == c[i] + 1) go_dow = min(go_dow, p.first);
    for (auto p : dow[i])
      if (p.second == c[i] + 1) go_up = min(go_up, p.first);
    if (go_up <= n + 1) trans(go_up, i, c[i] + 1);
    if (go_dow <= n + 1) trans(i, go_dow, c[i] + 1);
  }
  printf("%d\n", c[n + 1]);
  return 0;
}
