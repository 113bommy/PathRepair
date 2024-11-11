#include <bits/stdc++.h>
using namespace std;
const int N = 11234;
int n, m;
int mt[N], nt[N];
int l[N], r[N], t[N];
bool vis[N];
vector<int> g[N];
bool kuhn(int at) {
  if (vis[at]) return false;
  vis[at] = 1;
  if (t[at] == 1) {
    for (int next = l[at]; next <= r[at]; next++) {
      if (mt[next] == -1) {
        mt[next] = at;
        nt[at] = next;
        return true;
      }
    }
    for (int next = l[at]; next <= r[at]; next++) {
      if (kuhn(mt[next])) {
        mt[next] = at;
        nt[at] = next;
        return true;
      }
    }
  } else {
    for (auto next : g[at]) {
      if (mt[next] == -1) {
        mt[next] = at;
        nt[at] = next;
        return true;
      }
    }
    for (auto next : g[at]) {
      if (kuhn(mt[next])) {
        mt[next] = at;
        nt[at] = next;
        return true;
      }
    }
  }
  return false;
}
int max_matching() {
  int mm = 0;
  bool upd = true;
  while (upd) {
    upd = false;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++) {
      if (nt[i] == -1 and kuhn(i)) {
        mm++;
        upd = 1;
      }
    }
  }
  return mm;
}
int main() {
  memset(mt, -1, sizeof mt);
  memset(nt, -1, sizeof nt);
  scanf("%d %d", &n, &m);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", t + 2 * i);
    if (t[2 * i] == 0) {
      int k;
      scanf("%d", &k);
      while (k--) {
        int x;
        scanf("%d", &x);
        g[2 * i].push_back(x);
      }
    } else if (t[2 * i] == 1) {
      scanf("%d %d", l + 2 * i, r + 2 * i);
    } else {
      ans += 2;
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      g[2 * i].push_back(a);
      g[2 * i].push_back(b);
      g[2 * i].push_back(c);
      nt[2 * i] = a;
      mt[a] = 2 * i;
      g[2 * i + 1].push_back(a);
      g[2 * i + 1].push_back(b);
      g[2 * i + 1].push_back(c);
      nt[2 * i + 1] = b;
      mt[b] = 2 * i + 1;
    }
  }
  n *= 2;
  cout << ans + max_matching() << endl;
  for (int i = 0; i < n; i++)
    if (nt[i] != -1) printf("%d %d\n", (i / 2) + 1, nt[i]);
  return 0;
}
