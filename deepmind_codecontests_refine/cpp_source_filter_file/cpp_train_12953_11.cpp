#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int oo = 1e9;
int n, m, na, nb;
int bit[N];
struct book {
  int x, y, len;
};
book a[N], b[N], ta[N], tb[N];
void prepare() {
  vector<int> tmp;
  map<int, int> pos;
  for (int i = 1; i <= n; ++i) tmp.push_back(ta[i].y);
  for (int j = 1; j <= m; ++j) {
    tmp.push_back(tb[j].y);
    tmp.push_back(tb[j].y + tb[j].len);
  }
  sort(tmp.begin(), tmp.end());
  int cnt = 0;
  for (int i = 0; i < tmp.size(); ++i) {
    if (i == 0 || tmp[i] > tmp[i - 1]) cnt++;
    pos[tmp[i]] = cnt;
  }
  for (int i = 1; i <= n; ++i) ta[i].y = pos[ta[i].y];
  for (int i = 1; i <= m; ++i)
    tb[i].len = pos[tb[i].y + tb[i].len], tb[i].y = pos[tb[i].y];
}
bool cmp(const book x, const book y) { return x.x < y.x; }
void upd(int pos, int val) {
  for (int i = pos; i < N; i += (i & -i)) bit[i] += val;
}
int get(int pos) {
  int res = 0;
  for (int i = pos; i > 0; i -= (i & -i)) res += bit[i];
  return res;
}
bool check(int len) {
  na = nb = 0;
  memset(bit, 0, sizeof bit);
  for (int i = 1; i <= n; ++i)
    if (a[i].len >= 2 * len) {
      ta[++na] = {a[i].x + len, a[i].y, a[i].len - len};
    }
  for (int i = 1; i <= n; ++i)
    if (b[i].len >= 2 * len) {
      tb[++nb] = {b[i].x, b[i].y + len, b[i].len - len};
    }
  if (!na || !nb) return false;
  prepare();
  vector<pair<pair<int, int>, int> > tmp;
  for (int i = 1; i <= na; ++i) {
    tmp.push_back({{ta[i].x, ta[i].y}, 0});
    tmp.push_back({{ta[i].x + ta[i].len + 1, ta[i].y}, 1});
  }
  sort(tmp.begin(), tmp.end());
  sort(tb + 1, tb + nb + 1, cmp);
  int ptr = 0;
  for (int i = 1; i <= nb; ++i) {
    while (ptr < tmp.size() && tmp[ptr].first.first <= tb[i].x) {
      int x = tmp[ptr].first.first, y = tmp[ptr].first.second,
          ti = tmp[ptr].second;
      ptr++;
      if (ti == 0)
        upd(y, 1);
      else
        upd(y, -1);
    }
    int val = get(tb[i].len) - get(tb[i].y - 1);
    if (val) return true;
  }
  return false;
}
signed main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].len);
  for (int i = 1; i <= n; ++i) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].len);
  int l = 0, r = oo;
  while (r > l) {
    int mid = (l + r + 1) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  printf("%d", l);
  return 0;
}
