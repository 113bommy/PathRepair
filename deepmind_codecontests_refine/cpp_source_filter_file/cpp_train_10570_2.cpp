#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
const long long INF = LLONG_MAX;
void build(long long init, long long l, long long r,
           pair<long long, long long> *st) {
  if (l != r) {
    build(2 * init + 1, l, (l + r) / 2, st);
    build(2 * init + 2, (l + r) / 2 + 1, r, st);
    st[init].first = max(st[2 * init + 1].first, st[2 * init + 2].first);
    st[init].second = 0;
    st[init].second =
        (st[init].second + (st[2 * init + 1].second) *
                               (st[init].first == st[2 * init + 1].first)) %
        M;
    st[init].second =
        (st[init].second + (st[2 * init + 2].second) *
                               (st[init].first == st[2 * init + 2].first)) %
        M;
  } else {
    st[init] = make_pair(-1, 0);
  }
}
void modify(long long init, long long l, long long r, long long ind,
            pair<long long, long long> x, pair<long long, long long> *st,
            long long L) {
  if (l != r) {
    if (ind <= (l + r) / 2) {
      modify(2 * init + 1, l, (l + r) / 2, ind, x, st, L);
    } else {
      modify(2 * init + 2, (l + r) / 2 + 1, r, ind, x, st, L);
    }
    st[init].first = max((st[2 * init + 1].first), (st[2 * init + 2].first));
    st[init].second = 0;
    st[init].second =
        (st[init].second + (st[2 * init + 1].second) *
                               (st[init].first == st[2 * init + 1].first)) %
        M;
    st[init].second =
        (st[init].second + (st[2 * init + 2].second) *
                               (st[init].first == st[2 * init + 2].first)) %
        M;
  } else {
    st[init] = x;
  }
}
void getans(long long init, long long l, long long r, long long ql,
            long long qr, pair<long long, long long> *ans,
            pair<long long, long long> *st, long long L) {
  if (r < ql || l > qr) {
    return;
  }
  ql = max(l, ql);
  qr = min(r, qr);
  if (l == ql && r == qr) {
    pair<long long, long long> foo;
    foo.first = max((*ans).first, st[init].first);
    foo.second = 0;
    foo.second =
        (foo.second + (st[init].second) * (foo.first == (st[init].first))) % M;
    foo.second =
        (foo.second + ((*ans).second) * (foo.first == ((*ans).first))) % M;
    (*ans) = foo;
    cout << (*ans).second;
    return;
  }
  getans(2 * init + 1, l, (l + r) / 2, ql, qr, ans, st, L);
  getans(2 * init + 2, (l + r) / 2 + 1, r, ql, qr, ans, st, L);
}
long long power_2(long long p1, long long p2, long long x = M) {
  if (p2 == 0) {
    return 1;
  }
  if (p2 == 1) {
    return p1 % x;
  }
  long long y = power_2(p1, p2 / 2, x);
  y = ((((y * y) % x) * power_2(p1, p2 % 2, x)) % x);
  return y;
}
long long inv(long long p1) { return power_2(p1, M - 2); }
long long fact(long long n) {
  long long i, nlt = 1;
  for (i = 1; i <= n; ++i) {
    nlt = (nlt * i) % M;
  }
  return nlt;
}
bool check_pr(long long x, vector<long long> *pr) {
  long long n = (*pr).size();
  long long i;
  for (i = 0; i < n && ((*pr)[i]) * ((*pr)[i]) <= x; ++i) {
    if (x % ((*pr)[i]) == 0) {
      return false;
    }
  }
  return true;
}
pair<long long, long long> inv(pair<long long, long long> x) {
  pair<long long, long long> ans;
  ans.first = x.second;
  ans.second = x.first;
  return ans;
}
void fth(long long st, vector<set<long long> > *edges, bool *visited,
         long long *mx, long long dist, long long *vt) {
  visited[st] = true;
  set<long long>::iterator it;
  *vt = ((*mx >= dist) ? (*vt) : st);
  *mx = max(*mx, dist);
  set<long long> x1 = (*edges)[st];
  for (it = x1.begin(); it != x1.end(); ++it) {
    if (!visited[*it]) {
      fth((*it), edges, visited, mx, dist + 1, vt);
    }
  }
}
void merge(long long *a, long long *b, long long *c, long long sz,
           long long x) {
  long long i, j;
  long long *d = new long long[x];
  fill(d, d + x, 0);
  for (i = 1; i <= x; ++i) {
    for (j = 1; j <= x; ++j) {
      long long val = (((i - 1) * power_2(10, sz, x)) % x + (j - 1)) % x;
      d[val] = (d[val] + ((a[(i - 1)] * b[(j - 1)]) % M)) % M;
    }
  }
  for (i = 1; i <= x; ++i) {
    c[i - 1] = (c[i - 1] + d[i - 1]) % M;
  }
}
long long gcd(long long a, long long b) {
  if (a > b) {
    return gcd(b, a);
  }
  if (a == b || a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
int main() {
  vector<pair<long long, long long> > xx;
  long long n, m, p, l, r, t1, q, x, y, z, a, b, c, sum = 0, mult = 1, t = 0;
  long long i, j, k;
  string s, s1, s2;
  double d, h, v, e;
  t1 = 1;
  double pi = 3.14159265359;
  a = 1e9 * 1e9;
  while (t1-- > 0) {
    cin >> n;
    for (i = 1; i <= n; ++i) {
      cin >> x;
      sum = sum + x;
      mult = max(x, sum);
    }
    cout << (2 * mult + 1) - x;
  }
  return 0;
}
