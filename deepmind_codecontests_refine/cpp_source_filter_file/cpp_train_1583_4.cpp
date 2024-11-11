#include <bits/stdc++.h>
using namespace std;
int ts, kk = 1;
template <class T>
inline T _sq(T a) {
  return a * a;
}
template <class T, class X>
inline T _pow(T a, X y) {
  T z = 1;
  for (int i = 1; i <= y; i++) {
    z *= a;
  }
  return z;
}
template <class T>
inline T _gcd(T a, T b) {
  a = _abs(a);
  b = _abs(b);
  if (!b) return a;
  return _gcd(b, a % b);
}
template <class T>
inline T _lcm(T a, T b) {
  a = _abs(a);
  b = _abs(b);
  return (a / _gcd(a, b)) * b;
}
template <class T>
inline T _extended(T a, T b, T &x, T &y) {
  a = _abs(a);
  b = _abs(b);
  T g, x1, y1;
  if (!b) {
    x = 1;
    y = 0;
    g = a;
    return g;
  }
  g = _extended(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
template <class T, class X>
inline T togglebit(T a, X i) {
  T t = 1;
  return (a ^ (t << i));
}
template <class T, class X, class Y>
inline T _bigmod(T n, X m, Y mod) {
  unsigned long long ret = 1, a = n % mod;
  while (m) {
    if (m & 1) ret = (ret * a) % mod;
    m >>= 1;
    a = (a * a) % mod;
  }
  ret %= mod;
  return (T)ret;
}
template <class T, class Y>
inline T _modinv(T n, Y mod) {
  return _bigmod(n, mod - 2, mod);
}
vector<int> primes, pos, v;
char str[1010], ans[1010];
void seive() {
  for (int i = 2; i <= 1000; i++) {
    bool chk = false;
    for (int j = 2; j <= i - 1; j++) {
      if (i % j == 0) chk = true;
    }
    if (!chk) primes.push_back(i);
  }
}
int cnt[30];
int main() {
  seive();
  str[0] = 'a';
  scanf("%s", str + 1);
  int len = strlen(str) - 1;
  for (int i = 1; i <= len; i++) {
    cnt[str[i] - 'a']++;
  }
  pos.push_back(1);
  for (int i = 0; i < ((int)primes.size()); i++) {
    if (primes[i] > len) break;
    if ((primes[i] * 2) > len) {
      pos.push_back(primes[i]);
    }
  }
  int lft = len - pos.size();
  bool chk = false;
  char ch;
  for (int i = 0; i <= 25; i++) {
    if (cnt[i] >= lft && chk == false) {
      chk = true;
      ch = (i + 'a');
      for (int j = lft + 1; j <= cnt[i]; j++) {
        v.push_back(i);
      }
    } else {
      for (int j = 1; j <= cnt[i]; j++) {
        v.push_back(i);
      }
    }
  }
  if (!chk) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 1; i <= len; i++) {
      ans[i] = '#';
    }
    for (int i = 0; i < ((int)pos.size()); i++) {
      ans[pos[i]] = (v[i] + 'A');
    }
    for (int i = 1; i <= len; i++) {
      if (ans[i] == '#') ans[i] = ch;
    }
    printf("%s\n", str + 1);
  }
  return 0;
}
