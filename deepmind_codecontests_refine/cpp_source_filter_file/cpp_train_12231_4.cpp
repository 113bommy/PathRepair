#include <bits/stdc++.h>
using namespace std;
int const N = 4e6 + 10, oo = 1e9, M = 2e5 + 3;
long long const OO = 1e18;
int mod = oo + 7;
double const eps = 1e-4, PI = acos(-1);
int n, aa[M], seg[M << 2], an[M];
pair<int, int> mdf[N];
vector<pair<pair<int, int>, pair<int, int> > > query;
void go(int at, int k) {
  int fr = at * k - k + 2, to = min(n * 1LL, at * 1LL * k + 1);
  query.push_back({{fr, to}, {aa[at], k}});
  for (int i = fr; i <= to; i++) {
    if (i * 1LL * k - k + 2 > n) break;
    go(i, k);
  }
}
void upd(int p, int l, int r, int at) {
  if (l == r && l == at) {
    seg[p]++;
    return;
  }
  if (l > at || r < at) return;
  int m = (l + r) >> 1;
  upd(p << 1, l, m, at);
  upd(p << 1 | 1, m + 1, r, at);
  seg[p] = seg[p << 1] + seg[p << 1 | 1];
}
int get(int p, int l, int r, int lx, int rx) {
  if (l > rx || r < lx) return 0;
  if (l >= lx && r <= rx) return seg[p];
  int m = (l + r) >> 1;
  return get(p << 1, l, m, lx, rx) + get(p << 1 | 1, m + 1, r, lx, rx);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> aa[i], mdf[i] = {aa[i], -i};
  for (int k = 1; k < n; k++) go(1, k);
  int org = n;
  for (int j = 0; j < (int)query.size(); j++, n++)
    mdf[n + 1] = {query[j].second.first, j};
  n++;
  sort(mdf + 1, mdf + n + 1);
  for (int i = 1; i <= n;) {
    int j = i;
    while (j <= n && mdf[j].first == mdf[i].first) j++;
    for (int r = i; r < j; r++) {
      if (mdf[r].second > -1) {
        int idx = mdf[r].second;
        an[query[idx].second.second] +=
            get(1, 1, org, query[idx].first.first, query[idx].first.second);
      }
    }
    for (int r = i; r < j; r++)
      if (mdf[r].second < 0) upd(1, 1, org, -mdf[r].second);
    i = j;
  }
  for (int i = 1; i < org; i++) cout << an[i] << ' ';
  return 0;
}
