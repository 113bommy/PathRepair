#include <bits/stdc++.h>
using namespace std;
const long long LINF = 1e18;
const long long INF = 1e9;
const long long MOD = 1e9 + 7;
long long strtoll(string s) {
  stringstream str(s);
  long long number = 0;
  str >> number;
  return number;
}
string lltostr(long long n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
long long power(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long t = power(a, b / 2, m);
  t = (t * t) % m;
  if (b & 1) t = (t * a) % m;
  return t;
}
long long llsqrt(long long x) {
  if (x == 0 || x == 1) return x;
  long long start = 1, end = x / 2, ans;
  while (start <= end) {
    long long mid = (start + end) / 2;
    if (mid * mid == x)
      return mid;
    else if (mid <= x / mid)
      ans = mid, start = mid + 1;
    else
      end = mid - 1;
  }
  return ans;
}
vector<long long> spf;
void sieve(long long size) {
  spf.resize(size + 1);
  for (long long i = 1; i <= size; ++i) spf[i] = i;
  for (long long i = 4; i <= size; i += 2) spf[i] = 2;
  for (long long i = 3; i * i <= size; ++i) {
    if (spf[i] == i) {
      for (long long j = i * i; j <= size; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  long long l = 0, p = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '-')
      l++;
    else
      p++;
  }
  if (p == 0) {
    cout << "NO";
    return 0;
  }
  if (l % p == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
