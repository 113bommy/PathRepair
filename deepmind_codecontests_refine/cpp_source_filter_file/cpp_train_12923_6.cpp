#include <bits/stdc++.h>
using namespace std;
template <class A>
void pr(A a) {
  cout << a;
  cout << '\n';
}
template <class A, class B>
void pr(A a, B b) {
  cout << a << ' ';
  pr(b);
}
template <class A, class B, class C>
void pr(A a, B b, C c) {
  cout << a << ' ';
  pr(b, c);
}
template <class A, class B, class C, class D>
void pr(A a, B b, C c, D d) {
  cout << a << ' ';
  pr(b, c, d);
}
template <class A>
void PR(A a, long long n) {
  for (long long i = (long long)(0); i < (long long)(n); i++) {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
}
long long check(long long n, long long m, long long x, long long y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}
const long long MAX = 1e9 + 7, MAXL = 1LL << 61, dx[4] = {-1, 0, 1, 0},
                dy[4] = {0, 1, 0, -1};
vector<pair<long long, long long> > calc(long long n) {
  vector<pair<long long, long long> > v;
  for (long long i = 2; i * i <= n; i++) {
    pair<long long, long long> p = pair<long long, long long>(i, 0);
    while (n % i == 0) {
      p.second++;
      n /= i;
    }
    if (p.second) v.push_back(p);
  }
  if (n > 1) v.push_back(pair<long long, long long>(n, 1));
  return v;
}
void Main() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > v = calc(m);
  long long ans = MAX;
  for (long long i = (long long)(0); i < (long long)(v.size()); i++) {
    long long x = n, c = 0;
    while (x) {
      c += x / v[i].first;
      x /= v[i].first;
    }
    ans = min(ans, c / v[i].second);
  }
  pr(ans);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Main();
  return 0;
}
