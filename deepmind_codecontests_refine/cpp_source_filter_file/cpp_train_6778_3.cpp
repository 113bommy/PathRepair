#include <bits/stdc++.h>
using namespace std;
template <class T>
T _abs(T n) {
  return (n < 0 ? -n : n);
}
template <class T>
T _max(T a, T b) {
  return (!(a < b) ? a : b);
}
template <class T>
T _min(T a, T b) {
  return (a < b ? a : b);
}
template <class T>
T sq(T x) {
  return x * x;
}
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
template <class T>
bool inside(T a, T b, T c) {
  return a <= b && b <= c;
}
template <class T>
void setmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
void setmin(T &a, T b) {
  if (b < a) a = b;
}
int fx[] = {0, 0, -1, 1};
int fy[] = {1, -1, 0, 0};
map<long long, long long> smap;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  long long tblock = n / m;
  for (long long i = 1; i <= m; i++) {
    long long temp = (i * i) % m;
    smap[temp] += tblock;
  }
  long long extra = (n * n) % m;
  for (long long i = 1; i <= extra; i++) {
    long long temp = (i * i) % m;
    smap[temp]++;
  }
  long long sum = 0;
  for (auto c : smap) {
    long long temp = c.first;
    long long koto1 = c.second;
    long long nxt = m - temp;
    nxt %= m;
    long long koto2 = smap[nxt];
    sum += koto1 * koto2;
  }
  cout << sum << endl;
}
