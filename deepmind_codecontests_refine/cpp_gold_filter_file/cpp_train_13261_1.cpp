#include <bits/stdc++.h>
using namespace std;
int const maxn = 2e5 + 10;
int n, q, pos[maxn], a[maxn];
vector<int> p[maxn];
long long ans[maxn], bit[maxn];
void add(int idx, int val) {
  while (idx < maxn) bit[idx] += val, idx += (idx & -idx);
}
long long get(int idx) {
  long long ret = 0;
  while (idx > 0) ret += bit[idx], idx -= (idx & -idx);
  return ret;
}
struct qry {
  int l, r, id;
  qry(int a, int b, int c) : l(a), r(b), id(c) {}
};
bool operator<(qry A, qry B) { return A.r < B.r; }
vector<qry> Q;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= (int)n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  for (int i = 1; i <= (int)n; i++)
    for (int j = i; j < maxn; j += i)
      if (pos[j]) {
        if (pos[j] < pos[i])
          p[pos[i]].push_back(pos[j]);
        else
          p[pos[j]].push_back(pos[i]);
      }
  for (int i = 1; i <= (int)q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    Q.push_back(qry(l, r, i));
  }
  sort((Q).begin(), (Q).end());
  int pt = 0;
  for (int i = 1; i <= (int)n; i++) {
    if (pt >= q) break;
    for (auto j : p[pos[a[i]]]) add(j, 1);
    while (Q[pt].r == i) {
      int id = Q[pt].id;
      ans[id] = get(i) - get(Q[pt].l - 1);
      pt++;
      if (pt >= q) break;
    }
  }
  for (int i = 1; i <= (int)q; i++) printf("%I64d\n", ans[i]);
}
