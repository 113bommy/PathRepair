#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e5 + 10;
int n, m, p, k, a[N];
vector<pair<int, int> > tr[N << 2], zero;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
vector<pair<int, int> > operator+(vector<pair<int, int> > a,
                                  vector<pair<int, int> > b) {
  if (!a.size()) return b;
  if (!b.size()) return a;
  vector<pair<int, int> > c = a;
  for (int i = 0; i < b.size(); i++) {
    bool flg = 0;
    for (int j = 0; j < c.size(); j++)
      if (c[j].first == b[i].first) {
        c[j].second += b[i].second;
        flg = 1;
        break;
      }
    if (!flg) c.push_back(b[i]);
  }
  sort(c.begin(), c.end(), cmp);
  while (c.size() >= k) {
    for (int i = 0; i < c.size(); i++) c[i].second -= c.back().second;
    c.pop_back();
  }
  return c;
}
void upd(int x) { tr[x] = tr[x << 1] + tr[x << 1 | 1]; }
void build(int x, int l, int r) {
  tr[x].clear();
  if (l == r) {
    tr[x].push_back(make_pair(a[l], 1));
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
  upd(x);
}
int tag[N << 2];
void dopsd(int x, int l, int r, int p) {
  tag[x] = p;
  tr[x].clear(), tr[x].push_back(make_pair(p, r - l + 1));
}
void psd(int x, int l, int r) {
  if (tag[x]) {
    int mid = (l + r) >> 1;
    dopsd(x << 1, l, mid, tag[x]), dopsd(x << 1 | 1, mid + 1, r, tag[x]);
    tag[x] = 0;
  }
}
void modify(int x, int l, int r, int lx, int rx, int p) {
  if (rx > l || lx > r) return;
  if (lx <= l && r <= rx) {
    dopsd(x, l, r, p);
    return;
  }
  psd(x, l, r);
  int mid = (l + r) >> 1;
  modify(x << 1, l, mid, lx, rx, p), modify(x << 1 | 1, mid + 1, r, lx, rx, p);
  upd(x);
}
vector<pair<int, int> > query(int x, int l, int r, int lx, int rx) {
  if (rx < l || lx > r) return zero;
  if (lx <= l && r <= rx) return tr[x];
  psd(x, l, r);
  int mid = (l + r) >> 1;
  return query(x << 1, l, mid, lx, rx) + query(x << 1 | 1, mid + 1, r, lx, rx);
}
int main() {
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  k = 100 / p;
  build(1, 1, n);
  zero.clear();
  int op, l, r, id;
  while (m--) {
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      scanf("%d", &id);
      modify(1, 1, n, l, r, id);
    } else {
      vector<pair<int, int> > t = query(1, 1, n, l, r);
      printf("%d ", t.size());
      for (int i = 0; i < t.size(); i++) printf("%d ", t[i].first);
      puts("");
    }
  }
  return 0;
}
