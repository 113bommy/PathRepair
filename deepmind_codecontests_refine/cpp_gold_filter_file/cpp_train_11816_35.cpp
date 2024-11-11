#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const long long INF = 1e18;
const long double EPS = 1e-12;
vector<pair<int, int> > vec;
bool reach(pair<int, int> a, pair<int, int> b) {
  if (a.first <= b.first && a.second <= b.second) {
    return true;
  } else {
    return false;
  }
}
bool comp(pair<int, int> a, pair<int, int> b) {
  if (reach(a, b)) {
    return true;
  } else {
    return false;
  }
}
int fac[200005];
int ifac[200005];
int mul(int x, int y) {
  long long z = 1LL * x * y;
  if (z >= mod) {
    z %= mod;
  }
  return (int)z;
}
int add(int x, int y) {
  int z = x + y;
  if (z >= mod) z -= mod;
  return z;
}
int modpow(int x, int p) {
  if (p == 0) {
    return 1;
  }
  if (p == 1) {
    return x;
  }
  int tmp = modpow(x, p / 2);
  tmp = mul(tmp, tmp);
  if (p % 2 == 1) tmp = mul(tmp, x);
  return tmp;
}
int ncr(int x, int y) {
  if (y > x) return 0;
  int net = fac[x];
  net = mul(net, ifac[y]);
  net = mul(net, ifac[x - y]);
  return net;
}
int from(pair<int, int> a, pair<int, int> b) {
  if (!reach(a, b)) return 0;
  int l = (b.first - a.first);
  int r = (b.second - a.second);
  int net = ncr(l + r, l);
  return net;
}
int dp[2005];
int main() {
  int h, n, w;
  cin >> h >> w >> n;
  int fl = 0;
  for (int i = 0; i < (int)n; i++) {
    int x, y;
    cin >> x >> y;
    vec.push_back(make_pair(x, y));
    if (x == 1 && y == 1) {
      fl = 1;
    }
  }
  if (fl) {
    cout << "0" << endl;
    return 0;
  }
  sort(vec.begin(), vec.end());
  vec.push_back(make_pair(h, w));
  fac[0] = 1;
  ifac[0] = 1;
  int m = 100000;
  for (int i = (int)1; i < (int)2 * m + 1; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
  ifac[2 * m] = modpow(fac[2 * m], mod - 2);
  for (int i = 2 * m - 1; i >= 1; i--) {
    ifac[i] = mul(ifac[i + 1], i + 1);
  }
  for (int i = 0; i < (int)vec.size(); i++) {
    dp[i] = from(make_pair(1, 1), vec[i]);
    for (int j = (int)0; j < (int)i; j++) {
      int tmp = mul(dp[j], from(vec[j], vec[i]));
      dp[i] = add(dp[i], mod - tmp);
    }
  }
  int si = (int)vec.size();
  cout << dp[si - 1] << endl;
  return 0;
}
