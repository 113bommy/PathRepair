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
vector<long long> v[333333];
long long n, s, t;
long long dfs(long long x, long long p) {
  if (x == t) return -1;
  long long cnt = 0;
  for (long long i = (long long)(0); i < (long long)(v[x].size()); i++) {
    long long y = v[x][i];
    if (y == p) continue;
    long long d = dfs(y, x);
    if (d == -1) {
      if (x != s) return -1;
    } else
      cnt += d;
  }
  return cnt + 1;
}
void Main() {
  cin >> n >> s >> t;
  s--, t--;
  for (long long i = (long long)(0); i < (long long)(n - 1); i++) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  long long x = dfs(s, -1);
  swap(s, t);
  long long y = dfs(s, -1);
  pr(n * (n - 1) - x * y);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Main();
  return 0;
}
