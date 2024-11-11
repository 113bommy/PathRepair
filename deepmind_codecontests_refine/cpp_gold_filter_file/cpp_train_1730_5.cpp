#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-12;
const int inf = 2000000000;
const long long int infLL = (long long int)2e18;
long long int MOD = 1000000007;
int MOD1 = 1000000007;
int MOD2 = 1000000009;
inline bool checkBit(long long int n, long long int i) {
  return n & (1LL << i);
}
inline long long int setBit(long long int n, long long int i) {
  return n | (1LL << i);
  ;
}
inline long long int resetBit(long long int n, long long int i) {
  return n & (~(1LL << i));
}
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long int year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long int &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long int modMul(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long int modAdd(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long int modSub(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long int modPow(long long int b, long long int p) {
  long long int r = 1LL;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1LL;
  }
  return r;
}
inline long long int modDiv(long long int a, long long int b) {
  return modMul(a, modPow(b, MOD - 2));
}
bool comp(const pair<long long int, pair<long long int, long long int> > &p1,
          const pair<long long int, pair<long long int, long long int> > &p2) {
  return p1.first > p2.first;
}
bool comp1(const pair<long long int, long long int> &p1,
           const pair<long long int, long long int> &p2) {
  if (p1.first == p2.first) {
    return p1.second > p2.second;
  }
  return p1.first < p2.first;
}
long long int converter(string a) {
  long long int i, mul = 1, r, t, ans = 0LL;
  if (a.length() == 0) return 0;
  for (i = a.length() - 1; i >= 0; i--) {
    t = a[i] - '0';
    r = t % 10;
    ans += (mul * r);
    mul = mul * 10;
  }
  return ans;
}
int msb(unsigned x) {
  union {
    double a;
    int b[2];
  };
  a = x;
  return (b[1] >> 20) - 1023;
}
const int MAX = (int)2e6 + 5;
long long int cnt[MAX], sum[MAX], x, y, n;
bool vis[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, j, val;
  cin >> n >> x >> y;
  for (i = 1; i <= n; ++i) {
    cin >> val;
    sum[val] += val;
    cnt[val]++;
  }
  for (i = 1; i < MAX; ++i) {
    sum[i] += sum[i - 1];
    cnt[i] += cnt[i - 1];
  }
  long long int ans = infLL;
  for (i = 2; i < MAX; ++i) {
    if (vis[i] == true) continue;
    long long int now = 0LL, till = min(x / y + 1, i);
    for (j = i; j < MAX; j += i) {
      if (j != i) vis[j] = true;
      now += (((j * (cnt[j] - cnt[j - till])) - (sum[j] - sum[j - till])) * y);
      now += ((cnt[j - till] - cnt[j - i]) * x);
    }
    ans = min(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
