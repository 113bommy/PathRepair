#include <bits/stdc++.h>
using namespace std;
const long long B = 5051;
const long long M = 1e9 + 9;
long long n, m;
vector<pair<long long, long long> > p, q;
pair<long long, long long> operator-(pair<long long, long long> a,
                                     pair<long long, long long> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
void no() {
  cout << "NO" << endl;
  exit(0);
}
void yes() {
  cout << "YES" << endl;
  exit(0);
}
long long cross(pair<long long, long long> A, pair<long long, long long> B) {
  return A.first * B.second - A.second * B.first;
}
long long dot(pair<long long, long long> A, pair<long long, long long> B) {
  return A.first * B.first + A.second * B.second;
}
long long ccw(pair<long long, long long> o, pair<long long, long long> a,
              pair<long long, long long> b) {
  pair<long long, long long> oa = a - o;
  pair<long long, long long> ob = b - o;
  return cross(oa, ob);
}
long long hsh(vector<long long> v) {
  long long ret = 0;
  for (long long first : v) ret = (ret * B + first) % M;
  return (ret + M) % M;
}
vector<pair<long long, long long> > convex_hull(
    vector<pair<long long, long long> > pts) {
  sort(pts.begin(), pts.end());
  vector<pair<long long, long long> > hull;
  for (long long c = 2; c--;) {
    long long start = hull.size();
    for (pair<long long, long long> P : pts) {
      while (hull.size() >= start + 2 and
             ccw(hull[hull.size() - 2], hull[hull.size() - 1], P) <= 0)
        hull.pop_back();
      hull.push_back(P);
    }
    hull.pop_back();
    reverse(pts.begin(), pts.end());
  }
  return hull;
}
long long out(pair<long long, long long> a, pair<long long, long long> b,
              pair<long long, long long> c) {
  long long first = ccw(a, b, c) + 13;
  long long second = dot(b - a, b - a) + 17;
  return ((first % M * B + second % M) % M + M) % M;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    long long first, second;
    cin >> first >> second;
    p.push_back({first, second});
  }
  for (long long i = 0; i < m; i++) {
    long long xa, ya;
    cin >> xa >> ya;
    q.push_back({xa, ya});
  }
  p = convex_hull(p);
  q = convex_hull(q);
  if (p.size() != q.size()) no();
  if (p.size() == 1) yes();
  n = p.size();
  vector<long long> pp, qq;
  for (long long i = 0; i < n; i++) {
    long long j = (i + 1) % n;
    long long k = (i + 2) % n;
    pp.push_back(out(p[i], p[j], p[k]));
    qq.push_back(out(q[i], q[j], q[k]));
  }
  long long hp = hsh(pp);
  long long hq = hsh(qq);
  long long bb = 1;
  for (long long i = 0; i < n - 1; i++) bb = bb * B % M;
  for (long long i = 0; i < n; i++) {
    hq = (((hq - qq[i] * bb) % M * B % M + qq[i]) % M + M) % M;
    if (hq == hp) yes();
  }
  no();
  return 0;
}
