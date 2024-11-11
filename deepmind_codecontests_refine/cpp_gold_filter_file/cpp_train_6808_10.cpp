#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
inline int sbt(int x) { return __builtin_popcount(x); }
inline long long gl(long long a, long long b) { return (b - a + 1); }
inline long long mul(long long a, long long b,
                     long long m = (long long)(1e9 + 7)) {
  return ((a % m) * (b % m)) % m;
}
inline long long add(long long a, long long b,
                     long long m = (long long)(1e9 + 7)) {
  return (a + b) % m;
}
inline long long sub(long long a, long long b,
                     long long m = (long long)(1e9 + 7)) {
  return (a - b + m) % m;
}
long long fastpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
long long modinv(long long a) { return fastpow(a, (long long)(1e9 + 7) - 2); }
void get_ac() {
  string s, t = "";
  cin >> s;
  int i = 0, n = (long long)(s.length()) - 1;
  for (int i = 0; i <= n; i++) {
    if (s[i] == '.') {
      t += "0";
    } else if (s[i] == '-') {
      if (s[i + 1] == '.') {
        t += "1";
      } else {
        t += "2";
      }
      i++;
    }
  }
  cout << t;
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  { get_ac(); }
  return 0;
}
