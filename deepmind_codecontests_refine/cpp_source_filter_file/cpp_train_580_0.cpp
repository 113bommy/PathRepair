#include <bits/stdc++.h>
using namespace std;
long long int A[200005];
long long int ans[200005];
long long int gcd(long long int x, long long int y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
long long int euler(long long int n) {
  long long int ret = n;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ret /= i;
      ret *= (long long int)(i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n != 1) {
    ret /= n;
    ret *= (long long int)(n - 1);
  }
  return ret;
}
long long int mpow(long long int m, long long int t, long long int mod) {
  if (t == 0) return 1LL;
  long long int ret = mpow(m * m % mod, t / 2, mod);
  if (t % 2 == 1) ret = ret * m % mod;
  return ret;
}
void solve(vector<pair<long long int, int> > vec, long long int T,
           long long int K) {
  long long int inv = mpow(K, euler(T) - 1, T);
  vector<pair<long long int, int> > vx;
  for (int i = 0; i < vec.size(); i++) {
    pair<long long int, int> p = vec[i];
    p.first = p.first * inv % T;
    vx.push_back(p);
  }
  sort(vx.begin(), vx.end());
  for (int i = 0; i < vx.size();) {
    int f = i;
    for (; i < vx.size() && vx[f].first == vx[i].first; i++) {
      int v = vx[i].second;
      ans[v] = 0;
    }
    long long int nxt;
    if (i < vx.size())
      nxt = vx[i].first;
    else
      nxt = vx[0].first + T;
    ans[vx[f].second] = nxt - vx[f].first;
  }
}
int main() {
  long long int T;
  int n;
  scanf("%lld %d", &T, &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &A[i]);
    if (i > 0) A[i] += A[i - 1];
  }
  long long int K = A[n - 1];
  long long int g = gcd(T, K);
  vector<pair<long long int, int> > vx;
  for (int i = 0; i < n; i++)
    vx.push_back(pair<long long int, int>(A[i] % g, i));
  sort(vx.begin(), vx.end());
  for (int i = 0; i < n;) {
    vector<pair<long long int, int> > vec;
    int f = i;
    for (; i < n && vx[f].first == vx[i].first; i++) {
      int v = vx[i].second;
      vec.push_back(pair<long long int, int>(A[v] / g, v));
    }
    solve(vec, T / g, K / g);
  }
  for (int i = 0; i < n; i++) {
    if (i != 0) printf(" ");
    printf("%lld", ans[i]);
  }
  puts("");
  return 0;
}
