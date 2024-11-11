#include <bits/stdc++.h>
using namespace std;
template <class T>
const T& max(const T& a, const T& b, const T& c) {
  return max(a, max(b, c));
}
template <class T>
const T& min(const T& a, const T& b, const T& c) {
  return min(a, min(b, c));
}
void sc(int& a) { scanf("%d", &a); }
void sc(long long& a) { scanf("%lld", &a); }
void sc(int& a, int& b) {
  sc(a);
  sc(b);
}
void sc(long long& a, long long& b) {
  sc(a);
  sc(b);
}
void sc(int& a, int& b, int& c) {
  sc(a, b);
  sc(c);
}
void sc(long long& a, long long& b, long long& c) {
  sc(a, b);
  sc(c);
}
void prl(int a) { printf("%d\n", a); }
void prl(long long a) { printf("%lld\n", a); }
void prl() { printf("\n"); }
void prs(int a) { printf("%d ", a); }
void prs(long long a) { printf("%lld ", a); }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long poww(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = poww(a, b / 2);
  return (b & 1 ? a * tmp * tmp : tmp * tmp);
}
long long sumOfDigs(string s) {
  long long sum = 0;
  for (int i = 0; i < s.length(); i++) sum += s[i] - '0';
  return sum;
}
long long sumOfDigs(long long n) {
  return (n < 10 ? n : n % 10 + sumOfDigs(n / 10));
}
string itos(long long i) {
  string s = "";
  while (i) {
    s += char(i % 10 + '0');
    i /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long stoi(string& s) {
  long long tot = 0;
  for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10) {
    tot += j * (s[i] + '0');
  }
  return tot;
}
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
using namespace std;
long long mod = 1e9 + 7;
void tt() { freopen("test.txt", "r", stdin); }
long long modpower(long long x, long long y, long long p) {
  x %= mod;
  if (!y) return 1;
  long long res = 1;
  if (y & 1) {
    res *= x;
    res %= p;
  }
  long long z = modpower(x, y / 2, p);
  z %= p;
  z *= z;
  z %= mod;
  res *= z;
  res %= p;
  return res;
}
long long digSum(long long x) {
  long long res = 0;
  while (x) {
    res += (x % 10);
    x /= 10;
  }
  return res;
}
int dp[1000 * 1000 + 10], pre[1000 * 1000 + 10];
int main() {
  int n, k, w;
  cin >> n >> k >> w;
  string s;
  cin >> s;
  s = '0' + s;
  for (int i = 1; i < (int)s.length(); i++) pre[i] = pre[i - 1] + (s[i] - '0');
  for (int i = 1; i <= min(k, (int)s.length() - 1); i++) dp[i] = s[i] - '0';
  for (int i = k; i < (int)s.length(); i++) dp[i] = dp[i - k] + (s[i] - '0');
  for (int i = 1; i <= w; i++) {
    int l, r;
    cin >> l >> r;
    int tot = 0;
    int req = (r - l + 1) / k;
    int present = dp[r] - dp[l - 1];
    tot += (req - present);
    int extra = pre[r] - pre[l - 1] - present;
    tot += extra;
    cout << tot << endl;
  }
  return 0;
}
