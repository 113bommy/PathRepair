#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > seq;
set<pair<int, int> >::iterator it;
int n, A[100005], l[100005], r[100005], fa[100005];
int main() {
  scanf("%d%d", &n, &A[1]);
  seq.insert(make_pair(A[1], 1));
  for (int i = 2; i <= n; i++) {
    scanf("%d", &A[i]);
    it = seq.upper_bound(make_pair(A[i], i));
    if (it != seq.end() && !l[(*it).second])
      l[(*it).second] = i, fa[i] = (*it).second;
    else if (!r[(*--it).second])
      r[(*it).second] = i, fa[i] = (*it).second;
    seq.insert(make_pair(A[i], i));
  }
  for (int i = 2; i <= n; i++) printf("%d ", fa[A[i]]);
  printf("\n");
  return 0;
}
