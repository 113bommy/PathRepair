#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int infi = 1147483600;
const long long infl = 1e17;
const char ENDL = '\n';
struct RMQ {
 private:
  int N;
  vector<long long> node;
  long long e;

 public:
  RMQ() {}
  RMQ(long long e) : e(e) {}
  void __init__(int sz) {
    N = 1;
    while (N < sz) N *= 2;
    node.resize(2 * N - 1, e);
  }
  void build(vector<long long> &v) {
    int sz = int(v.size());
    __init__(sz);
    for (long long i = 0; i < (long long)sz; i++) {
      node[i + N - 1] = v[i];
    }
    for (int i = N - 2; i >= 0; i--) {
      node[i] = (node[i * 2 + 1] + node[i * 2 + 2]);
    }
  }
  void update(int k, long long x) {
    k += N - 1;
    node[k] = x;
    while (k > 0) {
      k = (k - 1) / 2;
      node[k] = (node[2 * k + 1] + node[2 * k + 2]);
    }
  }
  void renew(int b, int e, long long x) {
    renew(b, e, 0, 0, N, x);
    return;
  }
  void renew(int b, int e, int k, int l, int r, long long x) {
    if (e <= 0 || b >= N) return;
    if (k > 0) {
      node[k] = (node[k] + node[(k - 1) / 2]);
    }
    if (r < b || e < l) return;
    if (b <= l && r <= e) {
      node[k] = (node[k] + (r - l) * x);
      return;
    } else if (k < N - 1) {
      renew(b, e, 2 * k + 1, l, (l + r) / 2, x);
      renew(b, e, 2 * k + 2, (l + r) / 2, r, x);
      return;
    }
    return;
  }
  long long get(int i) {
    int k = i + N - 1;
    long long res = node[k];
    while (k > 0) {
      k = (k - 1) / 2;
      res = (res + node[k]);
    }
    return res;
  }
  long long query(int a, int b) { return query(a, b, 0, 0, N); }
  long long query(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) return e;
    if (a <= l && r <= b) return node[k];
    long long vl, vr;
    vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return (vl + vr);
  }
  void recalc() {
    for (long long k = 0; k < (long long)N - 1; k++) {
      node[2 * k + 1] = (node[2 * k * 1] + node[k]);
      node[2 * k + 2] = (node[2 * k * 2] + node[k]);
    }
  }
  long long show_one(int i) { return node[i + N - 1]; }
  void show() {
    for (long long i = 0; i < (long long)N; i++) cout << node[i] << " ";
    cout << endl;
    return;
  }
};
RMQ rmq(0);
int n, m, q;
int was[500005];
vector<long long> bord;
vector<int> city2;
void maekeisan() {
  vector<pair<int, int>> city;
  map<int, int> cnt;
  for (long long i = 0; i < (long long)n; i++) {
    cnt[was[i]]++;
  }
  for (long long i = 0; i < (long long)m; i++) {
    city.emplace_back(make_pair(cnt[i], i));
  }
  sort((city).begin(), (city).end());
  bord.emplace_back(0);
  long long now = 1;
  city2.emplace_back(city[0].second);
  while (now < m) {
    bord.emplace_back(bord.back() +
                      (city[now].first - city[now - 1].first) * now);
    city2.emplace_back(city[now].second);
    now++;
  }
  bord.emplace_back(infl);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> q;
  for (long long i = 0; i < (long long)n; i++) {
    cin >> was[i];
    was[i]--;
  }
  maekeisan();
  vector<pair<long long, long long>> query(q);
  vector<set<int>> need(m + 50);
  for (long long xx = 0; xx < (long long)q; xx++) {
    long long k;
    cin >> k;
    k -= n + 1;
    int idx = upper_bound((bord).begin(), (bord).end(), k) - bord.begin();
    query[xx] = make_pair(idx - 1, (k - bord[idx - 1]) % idx);
    need[idx - 1].insert(query[xx].second);
  }
  RMQ seg(0);
  map<pair<int, int>, int> ans;
  seg.__init__(m);
  for (long long i = 0; i < (long long)m; i++) {
    seg.update(city2[i], 1);
    for (auto x : need[i]) {
      int MIN = 0, MAX = m;
      while (MIN + 1 < MAX) {
        int MED = (MIN + MAX) / 2;
        if (seg.query(0, MED) <= x) {
          MIN = MED;
        } else {
          MAX = MED;
        }
      }
      ans[make_pair(i, x)] = MIN;
    }
  }
  for (long long xx = 0; xx < (long long)q; xx++)
    cout << ans[query[xx]] + 1 << ENDL;
}
