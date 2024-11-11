#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long int infLL = 90000000000000000;
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
  a %= 1000000000007LL;
  (a < 0) && (a += 1000000000007LL);
}
inline long long int modMul(long long int a, long long int b) {
  a %= 1000000000007LL, b %= 1000000000007LL;
  normal(a), normal(b);
  return (a * b) % 1000000000007LL;
}
inline long long int modAdd(long long int a, long long int b) {
  a %= 1000000000007LL, b %= 1000000000007LL;
  normal(a), normal(b);
  return (a + b) % 1000000000007LL;
}
inline long long int modSub(long long int a, long long int b) {
  a %= 1000000000007LL, b %= 1000000000007LL;
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
  return modMul(a, modPow(b, 1000000000007LL - 2));
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
vector<long long int> segment;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, n, a, b, k, l, r, t, gap, av_now, sneed, place, add, j,
      tot = 0LL;
  vector<long long int> ans;
  string s;
  cin >> n >> a >> b >> k;
  cin >> s;
  l = -1;
  r = 0;
  t = s.size();
  for (i = 0; i < s.length(); i++) {
    if (s[i] == '1' || i == t - 1) {
      r = i;
      if (i == t - 1 && s[i] == '0') r++;
      gap = r - l - 1;
      place = gap / b;
      tot += place;
      l = i;
    }
  }
  long long int target = tot - a + 1;
  l = -1;
  long long int till;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == '1' || i == t - 1) {
      if (l == -1)
        till = 0;
      else
        till = l;
      if (s[i] == '0' && i == t - 1)
        r = i;
      else
        r = i - 1;
      for (j = till + b - 1; j < r && target > 0; j += b) {
        ans.push_back(j);
        target--;
      }
      l = i + 1;
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
  return 0;
}
