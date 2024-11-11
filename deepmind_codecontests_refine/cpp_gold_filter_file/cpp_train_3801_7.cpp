#include <bits/stdc++.h>
using namespace std;
inline int Set(int N, int pos) { return N = N | (1 << pos); }
inline int Reset(int N, int pos) { return N = N & ~(1 << pos); }
inline bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
template <class T>
T gcd(T a, T b) {
  return (!b) ? a : gcd(b, a % b);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd(a, b)) * b;
}
template <class T>
bool is_prime(T n) {
  if ((n % 2 == 0 && n > 2) || n < 2) return 0;
  for (T i = 3; i * i <= n; i = i + 2) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  vector<pair<long long, long long> > v;
  cin >> n;
  for (long long i = 1; i <= min(3000000LL, n); i++) {
    long long u = 6 * n + (i * i * i) - i;
    long long d = 3 * i * (i + 1);
    if (u / d < 0) continue;
    if (u / d < i) break;
    if (u % d == 0) {
      v.push_back(make_pair(i, u / d));
    }
  }
  int vsz = v.size();
  for (int i = 0; i < vsz; i++) {
    if (v[i].first != v[i].second) {
      v.push_back(make_pair(v[i].second, v[i].first));
    }
  }
  sort((v).begin(), (v).end());
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << ' ' << v[i].second << endl;
  }
  return 0;
}
