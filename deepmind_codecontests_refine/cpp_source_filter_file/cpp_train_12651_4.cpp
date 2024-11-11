#include <bits/stdc++.h>
using namespace std;
bool read_int(int& out) {
  int c = getchar();
  long long x = 0;
  int neg = 0;
  for (; !('0' <= c && c <= '9') && c != '-'; c = getchar()) {
    if (c == EOF) return false;
  }
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  if (c == EOF) return false;
  for (; '0' <= c && c <= '9'; c = getchar()) {
    x = x * 10 + c - '0';
  }
  out = neg ? -x : x;
  return true;
}
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
template <typename T>
istream& operator>>(istream& h, vector<T>& od) {
  for (int i = 0; i < od.size(); ++i) h >> od[i];
  return h;
}
template <typename T>
ostream& operator<<(ostream& h, const vector<T>& od) {
  for_each(od.begin(), od.end(), [&h](const T& x) { h << x << ' '; });
  return h;
}
template <typename T>
T qrt(T x) {
  return x * x;
}
inline bool intersect_1(int a, int b, int c, int d) {
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  return max(a, c) <= min(b, d);
}
vector<pair<int, int>> factor(const long long& n) {
  long long x = n;
  int g = sqrt(x);
  vector<pair<int, int>> v;
  for (int i = 2; i <= g && i <= x; ++i) {
    if (x % i == 0) {
      int j = 0;
      while (x % i == 0) {
        x /= i;
        ++j;
      }
      v.push_back(make_pair(i, j));
    }
  }
  if (x > 1) v.push_back(make_pair(x, 1));
  return v;
}
int main() {
  int n;
  cin >> n;
  map<int, pair<int, int>> g;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++g[x].first;
    g[x].second = i;
  }
  vector<pair<int, pair<int, int>>> res(g.begin(), g.end());
  sort(res.begin(), res.end(),
       [&](const pair<int, pair<int, int>>& l,
           const pair<int, pair<int, int>>& r) {
         return l.second.first == r.second.first
                    ? l.second.second > l.second.first
                    : l.second.first > r.second.first;
       });
  cout << res.begin()->first << '\n';
}
