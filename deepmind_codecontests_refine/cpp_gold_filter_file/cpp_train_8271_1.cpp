#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long fpow(long long n, long long k, int p = (int)1e9 + 7) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = 2 * acos((long double)0);
const int maxn = 4010;
const int maxc = 4010;
const int maxq = 20010;
int n, p, q;
int c[maxn];
int h[maxn];
int t[maxn];
int f[maxc];
vector<pair<int, int> > query[maxq];
int ans[maxq];
vector<pair<pair<int, int>, int> > itv;
priority_queue<pair<int, int> > pq;
int compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return make_pair(make_pair(-a.first.first, a.first.second), a.second) <
         make_pair(make_pair(-b.first.first, b.first.second), b.second);
}
void add(int c, int h, vector<pair<int, int> >& his) {
  for (int i = (maxc)-1; i >= (0); i--)
    if (i + c < maxc && f[i + c] < f[i] + h) {
      his.push_back(make_pair(i + c, f[i + c]));
      f[i + c] = f[i] + h;
    }
}
void rollback(vector<pair<int, int> >& his, vector<pair<int, int> >& his2) {
  for (int i = (int((his).size())) - 1; i >= (0); i--) {
    int u = his[i].first;
    int v = his[i].second;
    f[u] = v;
  }
  for (int i = (0); i < (int((his2).size())); i++) {
    pq.push(his2[i]);
  }
}
void go(int l, int r) {
  vector<pair<int, int> > his, his2;
  while (int((itv).size()) && itv.back().first.first <= l) {
    pq.push(make_pair(itv.back().first.second, itv.back().second));
    itv.pop_back();
  }
  while (int((pq).size()) && pq.top().first >= r) {
    int u = pq.top().second;
    add(c[u], h[u], his);
    his2.push_back(pq.top());
    pq.pop();
  }
  if (l == r) {
    for (int i = (0); i < (int((query[l]).size())); i++) {
      int u = query[l][i].first;
      int v = query[l][i].second;
      ans[v] = f[u];
    }
  } else {
    go(l, (l + r) >> 1);
    go(((l + r) >> 1) + 1, r);
  }
  rollback(his, his2);
}
void solve() {
  scanf("%d%d", &n, &p);
  for (int i = (0); i < (n); i++) {
    scanf("%d%d%d", c + i, h + i, t + i);
    itv.push_back(make_pair(make_pair(t[i], t[i] + p - 1), i));
  }
  sort((itv).begin(), (itv).end(), compare);
  scanf("%d", &q);
  for (int i = (0); i < (q); i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    query[a].push_back(make_pair(b, i));
  }
  go(0, maxq - 1);
  for (int i = (0); i < (q); i++) {
    printf("%d\n", ans[i]);
  }
}
int main() {
  solve();
  return 0;
}
