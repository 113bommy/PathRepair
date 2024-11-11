#include <bits/stdc++.h>
using namespace std;
int in() {
  int x;
  cin >> x;
  return x;
}
long long lin() {
  long long x;
  cin >> x;
  return x;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline void print(pair<T, T> p) {
  cout << "(" << p.first << "," << p.second << ") ";
}
template <class T>
inline void print(vector<pair<T, T>> v) {
  for (auto e : v) print(e);
  cout << "\n";
}
template <class T>
inline void print(T v) {
  for (auto e : v) cout << e << " ";
  cout << "\n";
}
long double eps = 1e-8;
unsigned xorshift() {
  static unsigned x = 123456789, y = 362436069, z = 521288629, w = 8867512;
  unsigned t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n) { return xorshift() % (n); }
double drnd() { return (double)(rnd(INT_MAX)) / INT_MAX; }
void shuffle(vector<int>& x) {
  int n = x.size();
  for (long long i = n - 1; i >= 1; i--) {
    swap(x[i], x[rnd(i - 1)]);
  }
}
clock_t start;
double time() { return (double)(clock() - start) / CLOCKS_PER_SEC; }
int main() {
  int T = in();
  while (T--) {
    long long n = in(), g = in(), b = in();
    if (g >= b) {
      cout << n << "\n";
      continue;
    }
    long long s = (n + 1) / 2;
    long long t = s;
    s = (s - 1) / g;
    t = t - s * g;
    long long ans = s * (g + b) + t;
    cout << max(ans, n) << "\n";
  }
}
