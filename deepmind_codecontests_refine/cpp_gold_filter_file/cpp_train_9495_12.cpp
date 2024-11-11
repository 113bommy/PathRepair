#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y = y - a / b * x;
}
inline ll inv(ll a, ll P) {
  ll x, y;
  exgcd(a, P, x, y);
  return (x + P) % P;
}
const int N = 10000005, K = 1000000;
ll f[N];
int main() {
  ios::sync_with_stdio(false);
  ll P = 1e12, M = 15e5;
  f[1] = 1;
  for (int i = 2; i <= M + 1; i++) f[i] = (f[i - 1] + f[i - 2]) % P;
  ll dd = f[M + 1] / K;
  ll invdd = inv(dd, K);
  ll n, a, d;
  cin >> n >> a >> d;
  ll kk = (a * invdd) % K, tt = (d * invdd) % K;
  cout << kk * M + 1 << ' ' << tt * M << endl;
  return 0;
}
