#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
string stin() {
  string s;
  cin >> s;
  return s;
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
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  int n = in();
  long long p = in();
  long double l = 0, r = 1e17;
  int iter = 5000;
  vector<pair<long long, long long>> v;
  long long bsum = 0;
  for (long long i = 0; i < n; i++) {
    int a = in(), b = in();
    bsum += a;
    v.emplace_back(a, b);
  }
  if (bsum <= p) {
    cout << -1 << "\n";
    return 0;
  }
  while (iter--) {
    long double mid = (l + r) / 2;
    long double sum = 0;
    for (long long i = 0; i < n; i++) {
      sum += max((long double)0, mid * v[i].first - v[i].second);
    }
    if (sum > mid * p)
      r = mid;
    else
      l = mid;
  }
  if (r == 1e17)
    cout << -1 << "\n";
  else
    cout << l << "\n";
}
