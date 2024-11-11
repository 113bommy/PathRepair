#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
using namespace std;
struct Trees {
  long long a, h;
  double l, r;
};
Trees trees[100001];
bool comp(Trees t1, Trees t2) { return t1.a < t2.a; }
double lazy[100001];
double s[100001];
void build(long long id, long long lo, long long hi) {
  if (lo == hi) {
    s[id] = 1;
    lazy[id] = 1;
    return;
  }
  lazy[id] = 1;
  s[id] = 1;
  long long mid = (lo + hi) >> 1;
  build(2 * id, lo, mid);
  build(2 * id + 1, mid + 1, hi);
}
void propogate(long long id) {
  if (lazy[id] != 1) {
    s[id] *= lazy[id];
    lazy[2 * id] *= lazy[id];
    lazy[2 * id + 1] *= lazy[id];
    lazy[id] = 1;
  }
}
void update(long long id, long long lo, long long hi, long long l, long long r,
            double val) {
  if (l > r) return;
  propogate(id);
  if (lo > r or hi < l) return;
  if (lo >= l and hi <= r) {
    s[id] *= val;
    lazy[2 * id] *= val;
    lazy[2 * id + 1] *= val;
    return;
  }
  long long mid = (lo + hi) >> 1;
  update(2 * id, lo, mid, l, r, val);
  update(2 * id + 1, mid + 1, hi, l, r, val);
}
double query(long long id, long long lo, long long hi, long long pos) {
  propogate(id);
  if (lo == hi) {
    return s[id];
  }
  long long mid = (lo + hi) >> 1;
  if (pos <= mid)
    return query(2 * id, lo, mid, pos);
  else
    return query(2 * id + 1, mid + 1, hi, pos);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> trees[i].a >> trees[i].h >> trees[i].l >> trees[i].r;
    trees[i].l /= (double)100;
    trees[i].r /= (double)100;
  }
  vector<pair<long long, long long>> mushrooms(m);
  for (long long i = 0; i < m; i++) {
    cin >> mushrooms[i].first >> mushrooms[i].second;
  }
  sort(mushrooms.begin(), mushrooms.end());
  sort(trees, trees + n, comp);
  build(1, 1, m);
  for (long long i = 0; i < n; i++) {
    long long xmax = trees[i].a + trees[i].h;
    long long xmin = trees[i].a + 1;
    long long posr = upper_bound(mushrooms.begin(), mushrooms.end(),
                                 make_pair(xmax + 1, (long long)0)) -
                     mushrooms.begin();
    posr--;
    long long posl = upper_bound(mushrooms.begin(), mushrooms.end(),
                                 make_pair(xmin, (long long)0)) -
                     mushrooms.begin();
    update(1, 1, m, posl + 1, posr + 1, (1 - trees[i].r));
    posr = upper_bound(mushrooms.begin(), mushrooms.end(),
                       make_pair(trees[i].a, (long long)0)) -
           mushrooms.begin();
    posr--;
    posl = upper_bound(mushrooms.begin(), mushrooms.end(),
                       make_pair(trees[i].a - trees[i].h, (long long)0)) -
           mushrooms.begin();
    update(1, 1, m, posl + 1, posr + 1, (1 - trees[i].l));
  }
  double ans = 0;
  for (long long i = 1; i <= m; i++) {
    ans += query(1, 1, m, i) * mushrooms[i - 1].second;
  }
  cout << fixed << setprecision(7);
  cout << ans;
}
