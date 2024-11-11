#include <bits/stdc++.h>
using namespace std;
const int inf = 200009;
struct nod {
  long long l, r;
  int idx;
  nod(long long l_, long long r_, int idx_) { l = l_, r = r_, idx = idx_; }
  nod() {}
} num[inf];
bool operator<(nod a, nod b) {
  if (a.r == b.r) return a.l > b.l;
  return a.r < b.r;
}
set<pair<long long, int> > s;
pair<long long, long long> org[inf];
int sol[inf];
int main() {
  int n, m;
  long long a;
  scanf("%d%d", &n, &m);
  scanf("%I64d%I64d", &org[0].first, &org[0].second);
  for (int i = 1; i < n; ++i) {
    scanf("%I64d%I64d", &org[i].first, &org[i].second);
    num[i - 1] = nod(org[i].first - org[i - 1].second,
                     org[i].second - org[i - 1].first, i);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%I64d", &a);
    s.insert(make_pair(a, i));
  }
  sort(num, num + n - 1);
  set<pair<long long, int> >::iterator it;
  for (int i = 0; i < n; ++i) {
    it = s.lower_bound(make_pair(num[i].l, 0));
    if (it == s.end()) continue;
    if ((*it).first <= num[i].r) {
      sol[num[i].idx] = it->second;
      s.erase(it);
    }
  }
  for (int i = 1; i < n; ++i)
    if (sol[i] == 0) {
      printf("No\n");
      return 0;
    }
  printf("Yes\n");
  for (int i = 1; i < n; ++i) printf("%d ", sol[i]);
  printf("\n");
}
