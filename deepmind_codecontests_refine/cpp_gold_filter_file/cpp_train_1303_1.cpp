#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[100005], a[100005], pre[100005], nxt[100005], id[100005];
set<pair<int, int> > s;
bool cmp(int a, int b) { return p[a] < p[b]; }
int calc(int i, int j) {
  if (i == j) return 1111111111;
  int d = (p[j] - p[i] + m) % m;
  if (i > j) d = (d + a[j]) % m;
  if (d <= a[i]) return 1;
  if (a[i] <= a[j]) return 1111111111;
  int s = a[i] - a[j];
  return (d - a[j] - 1) / s + 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i], &a[i]), p[i]--, id[i] = i;
  sort(id + 1, id + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    if (i < n)
      nxt[id[i]] = id[i + 1];
    else
      nxt[id[i]] = id[1];
    pre[nxt[id[i]]] = id[i];
  }
  for (int i = 1; i <= n; i++) s.insert(make_pair(calc(i, nxt[i]), i));
  while (s.begin()->first < 1111111111 && !s.empty()) {
    int i = s.begin()->second, j = s.begin()->first;
    s.erase(s.begin());
    s.erase(make_pair(calc(nxt[i], nxt[nxt[i]]), nxt[i]));
    s.erase(make_pair(calc(pre[i], i), pre[i]));
    p[i] = (p[i] + j) % m;
    a[i]--;
    nxt[i] = nxt[nxt[i]];
    pre[nxt[i]] = i;
    s.insert(make_pair(calc(i, nxt[i]), i));
    s.insert(make_pair(calc(pre[i], i), pre[i]));
  }
  printf("%d\n", s.size());
  for (set<pair<int, int> >::iterator it = s.begin(); it != s.end(); it++) {
    printf("%d ", it->second);
  }
  return 0;
}
