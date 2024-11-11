#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int i, n, j, v[4000], ans, x, ub, l[4000], q[4000], mn = 0, mi;
  bool used[4000];
  map<int, int> M, Q, D;
  set<int> S;
  multiset<int> MS;
  set<int>::iterator sit;
  multiset<int>::iterator msit;
  memset(used, 0, sizeof used);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    S.insert(v[i]);
  }
  for (i = 0, sit = S.begin(); sit != S.end(); sit++, i++) M[*sit] = i;
  ans = 1;
  v[0] = M[v[0]];
  D[v[0]]++;
  Q[v[0]]++;
  for (i = 1; i < n; i++) {
    v[i] = M[v[i]];
    if (v[i - 1] != v[i]) D[v[i]]++;
    Q[v[i]]++;
    if ((x = Q[v[i]]) > ans) ans = x;
  }
  if (S.size() == 1) {
    printf("%d\n", Q[0]);
    return 0;
  }
  for (i = 0; i < S.size(); i++) MS.insert(-D[i]);
  ub = -*(msit = MS.begin()) - *(++msit);
  for (i = 0; i < n; i++) {
    if (!used[v[i]]) {
      mn = 0;
      memset(q, 0, sizeof q);
      memset(l, 0, sizeof l);
      used[v[i]] = true;
      l[v[i]] = i;
      for (j = i + 1; j < n; j++) {
        if (v[j] == v[i])
          l[v[i]] = j;
        else {
          if (l[v[j]] < l[v[i]]) q[v[j]]++;
          l[v[j]] = j;
          if (mn < q[v[j]]) {
            mn = q[v[j]];
            mi = j;
          }
        }
      }
      mn *= 2;
      if (l[v[i]] > mi) mn++;
    }
    if (ans < mn) ans = mn;
    if (ans >= ub) break;
  }
  printf("%d\n", ans);
  return 0;
}
