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
void Main() {
  int h1, m1, h2, m2;
  scanf("%d:%d", &h1, &m1);
  scanf("%d:%d", &h2, &m2);
  long long d = h1 * 60 + m1 + h2 * 60 + m2;
  d /= 2;
  if (h1 * 60 + m1 > h2 * 60 + m2) d += 12 * 60;
  d %= 24 * 60;
  printf("%02d:%02d\n", d / 60, d % 60);
}
int main() {
  Main();
  return 0;
}
