#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-12;
const int inf = 2000000000;
const long long int infLL = (long long int)1e18;
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
  long long int i, mul = 1LL, r, t, ans = 0LL;
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
const int MAX = 20005;
int sum[55][MAX], dp[55][MAX], val[55][MAX], n, m, temp1[MAX], k;
deque<pair<int, int> > dq;
int maxi[MAX];
int backMaxi[2 * MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout.unsetf(ios::floatfield);
  cout.precision(20);
  cout.setf(ios::fixed, ios::floatfield);
  ;
  cin >> n >> m >> k;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> val[i][j];
      sum[i][j] = sum[i][j - 1] + val[i][j];
      if (j >= k)
        dp[i][j] =
            sum[i - 1][j] - sum[i - 1][j - k] + sum[i][j] - sum[i][j - k];
      else
        dp[i][j] = sum[i - 1][j] + sum[i][j];
      ans = max(ans, dp[i][j]);
    }
  }
  for (int i = 3; i <= n + 1; ++i) {
    dq.clear();
    for (int j = k; j <= m; ++j) {
      int curSum = sum[i][j] - sum[i][j - k];
      if (j == k)
        dq.push_back(pair<long long int, long long int>(j, dp[i - 1][j]));
      else {
        while (!dq.empty() && j - k >= dq.front().first) dq.pop_front();
        while (!dq.empty()) {
          pair<int, int> cur = dq.back();
          if (sum[i - 1][j] - sum[i - 1][cur.first] + cur.second < dp[i - 1][j])
            dq.pop_back();
          else
            break;
        }
        dq.push_back(pair<long long int, long long int>(j, dp[i - 1][j]));
      }
      int res =
          dq.front().second + sum[i - 1][j] - sum[i - 1][dq.front().first];
      int cur = maxi[j - k] + curSum + sum[i - 1][j] - sum[i - 1][j - k];
      temp1[j] = max(cur, curSum + res);
      maxi[j] = max(maxi[j - 1], dp[i - 1][j]);
    }
    dq.clear();
    for (int j = m; j >= k; --j) {
      int curSum = sum[i][j] - sum[i][j - k];
      if (j == m)
        dq.push_back(pair<long long int, long long int>(j, dp[i - 1][j]));
      else {
        while (!dq.empty() && j + k <= dq.front().first) dq.pop_front();
        while (!dq.empty()) {
          pair<int, int> cur = dq.back();
          if (sum[i - 1][cur.first - k] - sum[i - 1][j - k] + cur.second <
              dp[i - 1][j])
            dq.pop_back();
          else
            break;
        }
        dq.push_back(pair<long long int, long long int>(j, dp[i - 1][j]));
      }
      int res = dq.front().second + sum[i - 1][dq.front().first - k] -
                sum[i - 1][j - k];
      int cur = backMaxi[j + k] + curSum + sum[i - 1][j] - sum[i - 1][j - k];
      dp[i][j] = max(temp1[j], max(cur, curSum + res));
      ans = max(ans, dp[i][j]);
      backMaxi[j] = max(backMaxi[j + 1], dp[i - 1][j]);
    }
  }
  cout << ans << '\n';
  return 0;
}
