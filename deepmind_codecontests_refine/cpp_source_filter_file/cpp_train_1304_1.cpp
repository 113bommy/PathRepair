#include <bits/stdc++.h>
using namespace std;
int n, m, p[500000], a[500000], q[500000], ll[500000], rr[500000];
set<pair<int, int> > S;
int read() {
  int x = 0, k = 1;
  char c;
  c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') k = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * k;
}
bool cmp(int a, int b) { return p[a] < p[b]; }
int cal(int x, int y) {
  if (x == y) return 1000000000;
  int dis = (p[y] - p[x] + m) % m;
  if (y < x) dis = (dis + a[y]) % m;
  if (dis <= a[x]) return 1;
  if (a[x] <= a[y]) return 1000000000;
  return ceil((double)(dis - a[y] - 1) / (double)(a[x] - a[y])) + 1;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) p[i] = read() - 1, a[i] = read(), q[i] = i;
  sort(q + 1, q + 1 + n, cmp);
  for (int i = 1; i <= n; i++) ll[q[i]] = q[i - 1], rr[q[i]] = q[i + 1];
  rr[q[n]] = q[1], ll[q[1]] = q[n];
  for (int i = 1; i <= n; i++) {
    S.insert(make_pair(cal(i, rr[i]), i));
  }
  while (23333) {
    pair<int, int> now = *S.begin();
    if (now.first == 1000000000) break;
    int u = now.second;
    S.erase(S.begin());
    S.erase(make_pair(cal(rr[u], rr[rr[u]]), rr[u]));
    if (!S.empty()) S.erase(make_pair(cal(ll[u], u), ll[u]));
    p[u] += now.first;
    p[u] %= m;
    --a[u];
    rr[u] = rr[rr[u]], ll[rr[u]] = u;
    S.insert(make_pair(cal(ll[u], u), ll[u]));
    S.insert(make_pair(cal(u, rr[u]), u));
  }
  printf("%d\n", S.size());
  for (set<pair<int, int> >::iterator it = S.begin(); it != S.end(); it++)
    printf("%d ", (*it).second);
  puts("");
  return 0;
}
