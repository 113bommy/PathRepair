#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
long long power(long long x, unsigned long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power(x, y / 2) * power(x, y / 2);
  else
    return x * power(x, y / 2) * power(x, y / 2);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
signed main() {
  long long n;
  cin >> n;
  priority_queue<long long> a, b, c, d;
  for (long long i = 0; i < n; i++) {
    string s;
    long long x;
    cin >> s >> x;
    if (s == "11") a.push(x);
    if (s == "10") b.push(x);
    if (s == "01") c.push(x);
    if (s == "00") d.push(x);
  }
  long long ans = 0;
  long long x = 0, y = 0, z = 0;
  ;
  while (!a.empty()) {
    ans += a.top();
    x++;
    y++;
    a.pop();
    z++;
  }
  while (!b.empty() && !c.empty()) {
    ans += b.top();
    ans += c.top();
    x++;
    y++;
    z += 2;
    b.pop();
    c.pop();
  }
  long long p = 2 * x - z;
  if (a.empty() == true) {
    while (!b.empty()) {
      d.push(b.top());
      b.pop();
    }
  } else {
    while (!a.empty()) {
      d.push(a.top());
      a.pop();
    }
  }
  while (p > 0 && !d.empty()) {
    p--;
    ans += d.top();
    d.pop();
  }
  cout << ans << endl;
}
