#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v, V[20];
long long m, x, c[20], n, q[100], ans;
long long mul(long long x, long long y, long long mo) {
  long long t = x * y - (long long)((long double)x / mo * y) * mo;
  return (t % mo + mo) % mo;
}
long long power(long long x, long long y, long long mo) {
  long long s = 1;
  for (; y; y /= 2, x = mul(x, x, mo))
    if (y & 1) s = mul(s, x, mo);
  return s;
}
void divide(vector<pair<long long, long long> > &vec, long long m) {
  int tmp = 0;
  for (int i = 2; 1ll * i * i <= m; i++)
    if (m % i == 0) {
      vec.push_back(pair<long long, long long>(i, 0));
      for (; m % i == 0; m /= i, ++vec[tmp].second)
        ;
      ++tmp;
    }
  if (m != 1) vec.push_back(pair<long long, long long>(m, 1));
}
void solve(long long val) {
  if (val == 1) {
    ++ans;
    return;
  }
  long long phi = 1, top = 0, tmp = 1, v = x % val;
  for (int i = (int)(0); i <= (int)(n - 1); i++)
    if (c[i]) {
      phi *= ::v[i].first - 1;
      for (auto j : V[i])
        for (int k = (int)(1); k <= (int)(j.second); k++) q[++top] = j.first;
      for (int j = (int)(2); j <= (int)(c[i]); j++) {
        phi *= c[i];
        q[++top] = ::v[i].first;
      }
    }
  for (int i = (int)(1); i <= (int)(top); i++)
    if (power(v, phi / q[i], val) == 1) tmp *= q[i], phi /= q[i];
  ans += tmp;
}
void dfs(int x, long long val) {
  if (x == n) return solve(val);
  for (c[x] = 0; c[x] <= v[x].second; ++c[x])
    dfs(x + 1, val), val *= v[x].first;
}
int main() {
  scanf("%lld%lld", &m, &x);
  divide(v, m);
  n = v.size();
  for (int i = (int)(0); i <= (int)(n - 1); i++) divide(V[i], v[i].first - 1);
  dfs(0, 1);
  printf("%lld\n", ans);
}
