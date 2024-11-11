#include <bits/stdc++.h>
const long long INF = 2000000005;
const long long BIG_INF = 2000000000000000005;
const long long mod = 1000000007;
const long long P = 31;
const long double PI = 3.141592653589793238462643;
const double eps = 1e-9;
using namespace std;
vector<pair<long long, long long> > dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool valid(long long x, long long y, long long n, long long m) {
  return x >= 0 && y >= 0 && x < n && y < m;
}
mt19937 rng(1999999973);
const long long N = 100000 + 5;
long long p[N], h[N], n, k;
string s;
inline long long getHash(long long l, long long r) {
  return ((h[r] - h[l - 1] + mod) * p[n - r]) % mod;
}
void init() {
  p[0] = 1;
  for (long long i = 1; i < N; i++) p[i] = (p[i - 1] * P) % mod;
  s = '#' + s;
  for (long long i = 1; i <= n; i++) {
    h[i] = (h[i - 1] + p[i - 1] * (s[i] - 'a' + 1)) % mod;
  }
}
struct sub_str {
  long long l, r;
  sub_str(long long l, long long r) {
    this->l = l;
    this->r = r;
  }
  sub_str() {}
};
struct comp {
  bool operator()(const sub_str &a, const sub_str &b) const {
    if (s[a.l] != s[b.l]) {
      return s[a.l] > s[b.l];
    }
    long long l = 1, r = min(a.r - a.l + 1, b.r - b.l + 1);
    while (l != r) {
      long long mid = (l + r + 1) / 2;
      if (getHash(a.l, a.l + mid - 1) == getHash(b.l, b.l + mid - 1))
        l = mid;
      else
        r = mid - 1;
    }
    if (l == min(a.r - a.l + 1, b.r - b.l + 1)) {
      return a.r - a.l + 1 > b.r - b.l + 1;
    }
    return s[a.l + l - 1] > s[b.l + l - 1];
  }
};
priority_queue<sub_str, vector<sub_str>, comp> q;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> s >> k;
  n = s.size();
  init();
  for (long long i = 1; i <= n; i++) {
    q.push(sub_str(i, i));
  }
  for (long long i = 1; i < k; i++) {
    if (q.empty()) {
      cout << "No such line.";
      return 0;
    }
    sub_str cur = q.top();
    q.pop();
    if (cur.r + 1 <= n) q.push(sub_str(cur.l, cur.r + 1));
  }
  for (long long i = q.top().l; i <= q.top().r; i++) cout << s[i];
  return 0;
}
