#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, INF = 1e9 + 7, M = 10;
const long long MOD = (long long)1e18 + 3;
long long n;
string ans;
set<long long> s[10];
map<long long, string> m;
long long p10[11];
string toString(long long num) {
  string res;
  while (num) {
    res.push_back((char)(num % 10 + '0'));
    num /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
int getLen(long long num) {
  int res = 0;
  while (num) {
    ++res;
    num /= 10;
  }
  return res;
}
void relax(long long x, string str) {
  if (x > n || getLen(x) <= str.length()) return;
  if (m.count(x) && str.length() >= m[x].length()) return;
  s[m[x].length()].erase(x);
  m[x] = str;
  s[m[x].length()].insert(x);
}
string get(long long x) {
  if (m.count(x)) return m[x];
  return toString(x);
}
void generatePowers() {
  for (long long x = 2; x * x <= n; ++x) {
    long long c = x * x;
    int deg = 2;
    while (c <= n) {
      relax(c, toString(x) + "^" + toString(deg));
      c *= x;
      ++deg;
    }
  }
}
void generatePowerAndPower(int maxLen) {
  for (int i = 1; i < maxLen; ++i)
    for (int j = i; i + j + 1 <= maxLen; ++j) {
      for (long long x : s[i])
        for (long long y : s[j]) relax(x * y, get(x) + "^" + get(y));
    }
}
void generatePowerAndNumber(int maxLen) {
  for (int i = 1; i + 2 <= maxLen; ++i)
    for (long long x : s[i])
      for (long long y = 2; y < p10[maxLen - i - 1]; ++y)
        relax(x * y, toString(y) + "*" + get(x));
}
void relaxAns(string str) {
  if (str.length() < ans.length()) ans = str;
}
void calcAns(int maxLen) {
  for (int i = 1; 2 * i < maxLen; ++i) {
    for (long long x : s[i]) {
      long long y = n - x;
      relaxAns(get(x) + "+" + get(y));
      if (n % x == 0) relaxAns(get(x) + "*" + get(n / x));
    }
    for (long long x = 1; x < p10[i]; ++x) {
      long long y = n - x;
      relaxAns(toString(x) + "+" + get(y));
      if (n % x == 0) relaxAns(toString(x) + "*" + get(n / x));
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  p10[0] = 1;
  for (int i = 1; i <= 10; ++i) p10[i] = p10[i - 1] * 10;
  cin >> n;
  generatePowers();
  generatePowerAndPower(7);
  generatePowerAndNumber(7);
  ans = get(n);
  calcAns(getLen(n));
  cout << ans;
  return 0;
}
