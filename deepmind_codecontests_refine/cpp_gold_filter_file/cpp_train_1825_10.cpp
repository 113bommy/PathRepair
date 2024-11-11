#include <bits/stdc++.h>
using namespace std;
const long long N = 4e6 + 5, inf = 1e9 + 7;
long long n, k;
long long inv(vector<pair<long long, long long> >& v, long long n) {
  string s;
  cin >> s;
  v.emplace_back(pair<long long, long long>(0, s.back() - 'a'));
  long long p = 0;
  s = s.substr(0, s.size() - 2);
  v[p].first = stoi(s);
  for (long long i = 1; i < n; i++) {
    cin >> s;
    if (s.back() - 'a' != v[p].second)
      v.emplace_back(pair<long long, long long>(0, s.back() - 'a')), p++;
    s = s.substr(0, s.size() - 2);
    v[p].first += stoi(s);
  }
  for (long long i = 0; i <= p; i++) v[i].second++;
  return p + 1;
}
string s;
long long h[N], p[N], in[N], z = 29, pr[N], p1[N];
inline long long expo(long long n, long long k, long long p = inf) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
inline long long util(long long r, long long l) {
  return (h[r] - h[l] + inf) % inf * expo(pr[l], inf - 2) % inf;
}
void prep() {
  p[0] = 1;
  p1[0] = 1;
  for (long long i = 0; i < N - 1; i++)
    p[i + 1] = p[i] * z % inf, p1[i] = (p1[i - 1] + p[i]) % inf;
  in[N - 1] = expo(p[N - 1], inf - 2);
  for (long long i = N - 1; i >= 1; i--) in[i - 1] = in[i] * z % inf;
}
vector<pair<long long, long long> > v, u;
inline bool f(long long i) {
  if (v[i].second == u[k - 1].second && v[i].first >= u[k - 1].first &&
      v[i - k + 1].second == u[0].second && v[i - k + 1].first >= u[0].first)
    return 1;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long i, j, a, b, ans = 0, h1 = 0, pre = 1;
  cin >> n >> k;
  prep();
  n = inv(v, n);
  k = inv(u, k);
  if (k == 1) {
    for (i = 0; i < n; i++)
      if (v[i].second == u[0].second)
        ans += max(0LL, v[i].first - u[0].first + 1);
    return cout << ans, 0;
  }
  for (i = 1; i < k - 1; i++) {
    h1 += p1[u[i].first - 1] * u[i].second % inf * pre % inf;
    pre = pre * p[u[i].first] % inf;
  }
  h1 %= inf;
  pr[0] = 1;
  for (i = 1; i < n; i++) {
    h[i] = h[i - 1] + p1[v[i].first - 1] * v[i].second % inf * pr[i - 1] % inf;
    pr[i] = pr[i - 1] * p[v[i].first] % inf;
    h[i] %= inf;
    if (i >= k - 1 && f(i) && util(i - 1, i - k + 1) == h1) ans++;
  }
  cout << ans;
}
