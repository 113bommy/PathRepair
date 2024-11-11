#include <bits/stdc++.h>
using namespace std;
const long long maxvalue = 1e9;
long long count(long long first, long long last, long long first_value) {
  long long c = last - first + 1;
  return ((first_value - c + first_value + 1) * c) / 2;
}
string to_string1(long long n) {
  string s;
  while (n) s.push_back(n % 10 + 48), n /= 10;
  reverse(s.begin(), s.end());
  return s;
}
long long length(long long n) {
  long long p = 1;
  long long sum = 0;
  long long c = 1;
  while (1) {
    long long first = p;
    if (first > n) break;
    sum += count(first, min(p * 10 - 1, n), n - first + 1) * c;
    c++, p *= 10;
  }
  return sum;
}
long long opyat(long long n) {
  long long p = 1, c = 1;
  long long sum = 0;
  while (n >= p) {
    sum += (min(n, p * 10 - 1) - p + 1) * c;
    p *= 10, c++;
  }
  return sum;
}
void solve() {
  long long n;
  cin >> n;
  long long l = 1, r = maxvalue;
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (length(m) >= n)
      r = m;
    else
      l = m;
  }
  long long razn = n - length(l);
  r = l + 1, l = 1;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (opyat(m) < razn)
      l = m;
    else
      r = m;
  }
  long long a = l + 1;
  string s = to_string1(a);
  razn -= opyat(l);
  for (long long i = 1; i <= s.size(); i++) {
    if (razn - i == 0) {
      cout << s[i - 1] << '\n';
      return;
    }
  }
}
signed main() {
  long long q;
  cin >> q;
  while (q--) solve();
}
