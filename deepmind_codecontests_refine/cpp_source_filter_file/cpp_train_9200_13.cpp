#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using pcc = pair<char, char>;
using pdd = pair<double, double>;
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vc = vector<char>;
using vd = vector<double>;
template <typename T>
T POW(T a, T b) {
  T x = 1;
  while (b) {
    if (b & 1) x *= a;
    a *= a;
    b >>= 1;
  }
  return x;
}
template <typename T>
T mPOW(T a, T b, T M) {
  T x = 1;
  while (b) {
    if (b & 1) x = (x * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return x;
}
template <typename T>
T Sqrt(T a) {
  T x = (T)sqrt(a);
  if ((x + 1) * (x + 1) == a) x++;
  return x;
}
int main(int argc, char *argv[]) {
  ll n, m, k;
  scanf("%lld%*c%lld%*c%lld%*c", &(n), &(m), &(k));
  vector<ll> ara(n + 5), opcnt(m + 5), add(n + 5);
  vector<pair<pll, ll>> op(m + 5);
  ll i, j;
  for (i = 1; i <= n; i++) {
    scanf("%lld%*c", &(ara[i]));
  }
  for (i = 1; i <= m; i++) {
    scanf("%lld%*c%lld%*c%lld%*c", &(op[i].first.first), &(op[i].first.second),
          &(op[i].second));
  }
  for (i = 1; i <= k; i++) {
    ll x, y;
    scanf("%lld%*c%lld%*c", &(x), &(y));
    opcnt[x]++;
    opcnt[y + 1]--;
  }
  for (i = 1; i <= m; i++) {
    opcnt[i] += opcnt[i - 1];
    add[op[i].first.first] += (opcnt[i] * op[i].second);
    add[op[i].first.second + 1] -= (opcnt[i] * op[i].second);
  }
  for (i = 1; i <= n; i++) {
    add[i] += add[i - 1];
    ara[i] += add[i];
    printf("%d", (ara[i])), printf(" ");
  }
  return 0;
}
