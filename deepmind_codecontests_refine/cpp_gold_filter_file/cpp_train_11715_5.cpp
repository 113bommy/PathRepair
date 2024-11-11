#include <bits/stdc++.h>
using namespace std;
inline int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
template <typename T>
inline bool smax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool smin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline T pw(T a, long long b) {
  T c = 1;
  while (b) {
    if (b & 1) c = (c * a);
    a = a * a;
    b >>= 1;
  }
  return c;
}
struct mint {
  const static long long mod = 1e9 + 7;
  long long x;
  mint() : x(0) {}
  mint(long long x) : x(((x % mod) + mod) % mod){};
  mint operator+=(const mint& a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint operator-=(const mint& a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint operator*=(const mint& a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint& a) const { return mint(*this) += a; }
  mint operator-(const mint& a) const { return mint(*this) -= a; }
  mint operator*(const mint& a) const { return mint(*this) *= a; }
  bool operator==(const mint& a) const { return x == a.x; }
};
const int maxn = 1000010;
char c[maxn];
int n, m, k, pos[26];
mint p[maxn * 2];
int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", c);
  m = strlen(c);
  p[0] = 1;
  set<pair<int, int> > s;
  for (int i = 0; i < (k); i++) s.insert(pair<int, int>(0, i));
  for (int i = 0; i < (m); i++) {
    int x = c[i] - 'a';
    p[i + 1] = p[i] + (p[i] - (pos[x] ? p[pos[x] - 1] : 0));
    s.erase(pair<int, int>(pos[x], x));
    s.insert(pair<int, int>(i + 1, x));
    pos[x] = i + 1;
  }
  for (int i = (m); i < (n + m); i++) {
    int x = s.begin()->second;
    p[i + 1] = p[i] + (p[i] - (pos[x] ? p[pos[x] - 1] : 0));
    s.erase(pair<int, int>(pos[x], x));
    s.insert(pair<int, int>(i + 1, x));
    pos[x] = i + 1;
  }
  cout << p[m + n].x << endl;
  return 0;
}
