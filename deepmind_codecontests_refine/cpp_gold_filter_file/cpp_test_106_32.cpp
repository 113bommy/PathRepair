#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(1000001, true);
long long cha;
const int INF = 1000000000;
vector<vector<int>> g(0);
vector<pair<long long, long long>> t(0);
pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first) return a;
  if (b.first > a.first) return b;
  return make_pair(a.first, a.second + b.second);
}
void build(vector<long long> a, int v, int tl, int tr) {
  if (tl == tr)
    t[v] = make_pair(a[tl], 1);
  else {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = combine(t[v * 2], t[v * 2 + 1]);
  }
}
pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
  if (l > r) return make_pair(-INF, 0);
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  return combine(get_max(v * 2, tl, tm, l, min(r, tm)),
                 get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
void update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr)
    t[v] = make_pair(new_val, 1);
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, new_val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, new_val);
    t[v] = combine(t[v * 2], t[v * 2 + 1]);
  }
}
void swap(long long a, long long b) {
  a += b;
  b = a - b;
  a -= b;
}
unsigned long long binpow(long long a, long long n) {
  int res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
int phi(int n) {
  int result = n;
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  if (n > 1) result -= result / n;
  return result;
}
void pr(int n) {
  prime[0] = prime[1] = false;
  for (int i = 2; i <= n; ++i)
    if (prime[i])
      if (i * 1ll * i <= n)
        for (int j = i * i; j <= n; j += i) prime[j] = false;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    if (a == 0) {
      return -1;
    }
    return a;
  }
  return gcd(abs(b - a), a);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt, n;
  cin >> tt;
  pr(100000);
  vector<int> pri(1000);
  int last = 0;
  for (int i = 0; i < 1000; i++) {
    while (!prime[last]) {
      last++;
    }
    pri[i] = last;
    last++;
  }
  while (tt--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cout << pri[i] << " ";
    }
    cout << endl;
  }
}
