#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-12;
const int inf = 2000000000;
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
const int MAX = 100005;
int n, lim, lg[MAX], a[MAX], minval[MAX][21], maxval[MAX][21], l, s, b[MAX];
vector<pair<long long int, long long int> > ranges;
long long int dp[MAX];
int minquery(int i, int j) {
  int k = lg[j - i];
  int x = minval[i][k];
  int y = minval[j - (1 << k) + 1][k];
  return min(x, y);
}
int maxquery(int i, int j) {
  int k = lg[j - i];
  int x = maxval[i][k];
  int y = maxval[j - (1 << k) + 1][k];
  return max(x, y);
}
void SparseTable() {
  int i, j, l;
  lg[0] = lg[1] = 0;
  lim = 32 - __builtin_clz(n);
  for (i = 2; i < MAX; i++) lg[i] = lg[i >> 1] + 1;
  for (l = 0; l < lim; l++) {
    int len = (1 << l);
    for (i = 0; (i + len) <= n; i++) {
      if (l == 0)
        minval[i][l] = maxval[i][l] = a[i + 1];
      else {
        int d = 1 << (l - 1);
        minval[i][l] = min(minval[i][l - 1], minval[i + d][l - 1]);
        maxval[i][l] = max(maxval[i][l - 1], maxval[i + d][l - 1]);
      }
    }
  }
}
void no() {
  cout << "-1" << '\n';
  exit(0);
}
deque<pair<long long int, long long int> > dick;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int i, low, high, mid, maxi, cut;
  cin >> n >> s >> l;
  for (i = 1; i <= n; ++i) cin >> a[i];
  SparseTable();
  fill(dp + 1, dp + n + 1, (long long int)2e10);
  dp[0] = 0;
  dick.push_back(pair<long long int, long long int>(dp[0], 0));
  for (i = 1; i <= n; ++i) {
    low = 1, high = i;
    int now = i;
    while (low <= high) {
      mid = (low + high) >> 1;
      if (maxquery(mid - 1, i - 1) - minquery(mid - 1, i - 1) <= s) {
        high = mid - 1;
        now = min(mid, now);
      } else
        low = mid + 1;
    }
    while (!dick.empty() && dick.front().second < (now - 1)) dick.pop_front();
    if (!dick.empty() && dick.front().second <= i - l) {
      dp[i] = 1 + dick.front().first;
    }
    while (!dick.empty() && dick.back().first >= dp[i]) dick.pop_back();
    dick.push_back(pair<long long int, long long int>(dp[i], i));
  }
  if (dp[n] >= (long long int)2e10)
    cout << "-1" << '\n';
  else
    cout << dp[n] << '\n';
  return 0;
}
