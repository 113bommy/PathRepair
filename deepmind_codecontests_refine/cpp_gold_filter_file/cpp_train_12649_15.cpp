#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long double EPS = 1e-12;
const long double PI = acos(-1);
int n;
vector<int> pos;
int res = 1000000000;
bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }
bool isLower(char c) { return c >= 'a' && c <= 'z'; }
bool isLetter(char c) { return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }
bool isDigit(char c) { return c >= '0' && c <= '9'; }
char toLower(char c) { return (isUpper(c)) ? (c + 32) : c; }
char toUpper(char c) { return (isLower(c)) ? (c - 32) : c; }
bool isPowOf2(int i) { return (i & i - 1) == 0; }
bool srtDes(long long x, long long y) { return (x > y); }
long long gcd(long long a, long long b) {
  while (b) {
    long long temp = a % b;
    a = b, b = temp;
  }
  return a;
}
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
long long extended_euclid(long long a, long long b, long long& x,
                          long long& y) {
  long long xx = y = 0;
  long long yy = x = 1;
  while (b) {
    long long q = a / b;
    long long t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
long double pow(long double num, long long n) {
  long double res = 1;
  while (n) {
    if (n % 2 == 1) res *= num;
    num *= num;
    n /= 2;
  }
  return res;
}
bool isPrime(unsigned long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (unsigned long long i = 5; i <= sqrt(n); i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
void buildTable(string& w, vector<int>& t) {
  t = vector<int>(w.length());
  int i = 2, j = 0;
  t[0] = -1;
  t[1] = 0;
  while (i < w.length()) {
    if (w[i - 1] == w[j]) {
      t[i] = j + 1;
      i++;
      j++;
    } else if (j > 0)
      j = t[j];
    else {
      t[i] = 0;
      i++;
    }
  }
  return;
}
int kmp(string& s, string& w) {
  int m = 0, i = 0;
  vector<int> t;
  buildTable(w, t);
  while (m + i < s.length()) {
    if (w[i] == s[m + i]) {
      i++;
      if (i == w.length()) return m;
    } else {
      m += i - t[i];
      if (i > 0) i = t[i];
    }
  }
  return s.length();
}
void input();
void solve();
void output();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  solve();
  output();
  return 0;
}
void input() {
  cin >> n;
  pos.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> pos[i];
  }
  return;
}
void solve() {
  sort(pos.begin(), pos.end());
  int k = n / 2;
  for (int i = 1; i <= k; i++) res = min(res, pos[i + k] - pos[i]);
  return;
}
void output() {
  cout << res << endl;
  return;
}
