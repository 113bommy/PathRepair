#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
inline long long getPow(long long a, long long b) {
  long long res = 1, tp = a;
  while (b) {
    if (b & 1ll) {
      res *= tp;
    }
    tp *= tp;
    b >>= 1ll;
  }
  return res;
}
inline long long to_ll(string s) {
  long long cur = 0;
  for (int i = 0; i < s.size(); i++) {
    cur = cur * 10 + s[i] - '0';
  }
  return cur;
}
inline string to_str(long long x) {
  string s = "";
  while (x) {
    s += char(x % 10 + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
inline long long nxt() {
  long long x;
  scanf("%lld", &x);
  return x;
}
void ok() {
  puts("YES");
  exit(0);
}
void panic() {
  puts("NO");
  exit(0);
}
const long long N = 1e6 + 5;
int main() {
  map<long long, long long> mp;
  long long n = nxt();
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long x = nxt(), y = nxt();
    ans += mp[3000 + x - y]++ + mp[x + y]++;
  }
  cout << ans;
  return 0;
}
