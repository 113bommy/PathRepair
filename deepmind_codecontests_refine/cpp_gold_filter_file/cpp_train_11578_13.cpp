#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
vector<pair<int, int> > trap[MAXN + 10];
int m, n, k, t;
int S[MAXN + 10];
bool f(int energy) {
  int mx = -1;
  int tot = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < (int)trap[i + 1].size(); j++) {
      if (trap[i + 1][j].first > energy) mx = max(mx, trap[i + 1][j].second);
    }
    if (i < mx)
      tot += 3;
    else
      tot++;
  }
  return tot <= t;
}
int main() {
  scanf("%d %d %d %d", &m, &n, &k, &t);
  for (int i = 0; i < m; i++) scanf("%d", &S[i]);
  sort(S, S + m);
  for (int i = 0; i < k; i++) {
    int l, r, d;
    scanf("%d %d %d", &l, &r, &d);
    trap[l].push_back(make_pair(d, r));
  }
  int lo = 0, hi = m - 1, mid;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (!f(S[mid]))
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  printf("%d\n", m - lo);
  return 0;
}
