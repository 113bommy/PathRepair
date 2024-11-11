#include <bits/stdc++.h>
using namespace std;
const int T = 100000;
int a[100005], b[100005], Q[100005], opt[100005], n, m, i, j, k, id, debug;
long long pos, start, now;
set<pair<long long, int> > S;
int main() {
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &opt[i], &a[i]);
    if (opt[i] == 2) scanf("%d", &b[i]);
    if (opt[i] == 1) {
      if ((*Q) < T) Q[++*Q] = a[i];
      now++;
    } else
      for (now += 1ll * a[i] * b[i], j = 1; j <= b[i] && (*Q) < T; j++)
        for (k = 1; k <= a[i] && (*Q) < T; k++) Q[++*Q] = Q[k];
    S.insert(make_pair(now, i));
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &pos);
    if (pos <= T) {
      printf("%d ", Q[pos]);
      continue;
    }
    pair<long long, int> tmp = *S.lower_bound(make_pair(pos, 0));
    id = tmp.second;
    now = tmp.first;
    if (opt[id] == 1)
      printf("%d ", a[id]);
    else
      start = now - 1ll * a[id] * b[id],
      printf("%d ", Q[(pos - start - 1) % a[id] + 1]);
  }
}
