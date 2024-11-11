#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > seg;
int main() {
  int h, q;
  long long l, r;
  scanf("%d%d", &h, &q);
  l = 1LL << h - 1;
  r = 1LL << h;
  for (int i = 0; i < q; i++) {
    long long L, R;
    int yes, d;
    scanf("%d%I64d%I64d%d", &d, &L, &R, &yes);
    L = L << h - d;
    R = R + 1 << h - d;
    if (yes) {
      l = max(l, L);
      r = min(r, R);
    } else
      seg.push_back(make_pair(L, R));
  }
  sort(seg.begin(), seg.end());
  for (int i = 0; i < seg.size(); i++)
    if (seg[i].first <= l && l <= seg[i].second) l = seg[i].second;
  for (int i = seg.size() - 1; i >= 0; i--)
    if (seg[i].first <= r && r <= seg[i].second) r = seg[i].first;
  if (r <= l)
    printf("Game cheated!\n");
  else if (r - l > 1)
    printf("Data not sufficient!\n");
  else
    printf("%I64d\n", l);
  return 0;
}
