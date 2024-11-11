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
int main() {
  long long a = nxt(), b = nxt(), c = nxt();
  long long n = nxt();
  vector<long long> mas(n);
  for (int i = 0; i < n; i++) {
    mas[i] = nxt();
  }
  mas.push_back(b);
  mas.push_back(c);
  sort(mas.begin(), mas.end());
  long long l = (upper_bound(mas.begin(), mas.end(), b)) - mas.begin();
  long long r = (lower_bound(mas.begin(), mas.end(), c) - mas.begin());
  long long ans = r - l;
  cout << ans;
  return 0;
}
