#include <bits/stdc++.h>
using namespace std;
const int64_t N = 1e5 + 7, M = 2e5 + 7;
int64_t IX = 1e18, IN = -1e18;
int64_t ten[] = {
    1,           10,           100,           1000,          10000,
    100000,      1000000,      10000000,      100000000,     1000000000,
    10000000000, 100000000000, 1000000000000, 10000000000000};
vector<int64_t> s_match, prime;
void scan(int64_t &a, int64_t &b = IX, int64_t &c = IX) {
  scanf("%lld", &a);
  if (b != IX) scan(b, c);
}
int64_t power(int64_t a, int64_t b, int64_t c) {
  if (b == 0)
    return 1;
  else if (b % 2 == 1)
    return (a * power(a, b - 1, c)) % c;
  int64_t value = power(a, b / 2, c) % c;
  return (value * value) % c;
}
void find_prime(int64_t n) {
  vector<bool> visited(n, 1);
  int64_t i, j;
  for (i = 2; i < n; i++) {
    if (visited[i]) {
      prime.push_back(i);
      for (j = 2 * i; j < n; j += i) visited[j] = 0;
    }
  }
}
int64_t inverse(int64_t a) {
  return power(a, 1000000007 - 2, 1000000007) % 1000000007;
}
int64_t gcd(int64_t a, int64_t b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool K_matcher(string p, string q) {
  int64_t i, k, num[N], flag = 0;
  num[0] = -1;
  k = -1;
  for (i = 1; i < p.size(); i++) {
    while (k > -1 && p[k + 1] != p[i]) k = num[k];
    if (p[k + 1] == p[i]) k++;
    num[i] = k;
  }
  k = -1;
  for (i = 0; i < q.size(); i++) {
    while (k > -1 && p[k + 1] != q[i]) k = num[k];
    if (p[k + 1] == q[i]) k++;
    if (k == p.size() - 1) {
      s_match.push_back(i - p.size() + 1);
      k = num[k];
      flag = 1;
    }
  }
  if (flag)
    return 1;
  else
    return 0;
}
int64_t X[] = {1, 0, -1, 0}, Y[] = {0, 1, 0, -1};
pair<int64_t, int64_t> check(pair<int64_t, int64_t> p,
                             pair<int64_t, int64_t> q) {
  pair<int64_t, int64_t> r;
  if (p.first == IN && p.second == IN) return p;
  if (q.first == IN && q.second == IN) return q;
  r.first = max(p.first, q.first);
  r.second = min(p.second, q.second);
  if (r.first > r.second) return make_pair(IN, IN);
  return r;
}
vector<pair<int64_t, int64_t> > u, v, w;
int main() {
  int64_t n, i, a, b;
  scan(n);
  v.push_back(make_pair(IN, IX));
  for (i = 0; i < n; i++) {
    scan(a, b);
    v.push_back(make_pair(a, b));
  }
  v.push_back(make_pair(IN, IX));
  pair<int64_t, int64_t> p = make_pair(IN, IX);
  u.push_back(p);
  for (i = 1; i <= n; i++) {
    u.push_back(check(p, v[i]));
    p = check(p, v[i]);
  }
  p = make_pair(IN, IX);
  w.push_back(p);
  for (i = n - 1; i >= 0; i--) {
    w.push_back(check(p, v[i]));
    p = check(p, v[i]);
  }
  int64_t maxi = -1;
  for (i = 1; i <= n; i++) {
    p = check(u[i - 1], w[n - i]);
    if (p.first == IN && p.second == IN)
      maxi = max(maxi, (int64_t)0);
    else
      maxi = max(maxi, abs(p.second - p.first));
  }
  cout << maxi << endl;
}
