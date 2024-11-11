#include <bits/stdc++.h>
using namespace std;
bool operator<(pair<long double, int> i, pair<long double, int> j) {
  return i.first < j.first;
}
long double A[110000], m[110000], M[110000];
int S[110000][2], root, den;
long double Ans[110000], num;
set<pair<long double, int> > SS;
void tree(int v) {
  if (S[v][0] != -1) {
    tree(S[v][0]), tree(S[v][1]);
    m[v] = m[S[v][0]], M[v] = M[S[v][0]];
  } else
    m[v] = A[v], M[v] = A[v];
}
void solve(int v, long double mv) {
  if (S[v][0] == -1) {
    Ans[v] = num / den;
    SS.insert(make_pair(mv, v));
    return;
  }
  den++;
  num += m[S[v][1]];
  solve(S[v][0], mv);
  num -= m[S[v][1]];
  num += M[S[v][0]];
  solve(S[v][1], A[v]);
  num -= M[S[v][0]];
  den--;
}
int main() {
  int i, tmp, n, t;
  long double k;
  double tmpd;
  set<pair<long double, int> >::iterator it;
  memset(S, -1, sizeof(S));
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%lf", &tmp, &tmpd);
    if (tmp == -1)
      root = i;
    else {
      tmp--;
      if (S[tmp][0] == -1)
        S[tmp][0] = i;
      else
        S[tmp][1] = i;
    }
    A[i] = (long double)(tmpd);
  }
  for (i = 0; i < n; i++)
    if (S[i][0] != -1)
      if (A[S[i][0]] > A[S[i][1]]) swap(S[i][0], S[i][1]);
  tree(root);
  solve(root, -((long double)1e12));
  scanf("%d", &t);
  while (t > 0) {
    scanf("%lf", &tmpd);
    k = (long double)tmpd;
    it = SS.lower_bound(make_pair(tmpd, 0));
    it--;
    printf("%.10lf\n", (double)Ans[(*it).second]);
    t--;
  }
  return 0;
}
