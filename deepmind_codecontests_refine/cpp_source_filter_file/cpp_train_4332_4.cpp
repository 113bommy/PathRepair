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
  for (int i = (int)(0); i < (int)(n); i++) {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
}
long long check(long long n, long long m, long long x, long long y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}
const long long MAX = 1000000007, MAXL = 1LL << 61, dx[4] = {-1, 0, 1, 0},
                dy[4] = {0, 1, 0, -1};
void Main() {
  string s, t;
  cin >> s >> t;
  long long x = 0, c[26], d[26], e[26];
  memset(d, 0, sizeof(d));
  memset(e, 0, sizeof(e));
  for (int i = (int)(0); i < (int)(s.size()); i++) {
    if (s[i] == '?')
      x++;
    else
      e[s[i] - 'a']++;
  }
  for (int i = (int)(0); i < (int)(t.size()); i++) d[t[i] - 'a']++;
  long long l = 0, r = s.size() + 1;
  while (l + 1 < r) {
    long long m = (l + r) / 2;
    memset(c, 0, sizeof(c));
    for (int i = (int)(0); i < (int)(26); i++) c[i] += d[i] * m;
    for (int i = (int)(0); i < (int)(26); i++) c[i] = max(c[i], e[i]);
    int cnt = 0;
    for (int i = (int)(0); i < (int)(26); i++) cnt += max(0LL, c[i] - e[i]);
    if (cnt <= x)
      l = m;
    else
      r = m;
  }
  memset(c, 0, sizeof(c));
  for (int i = (int)(0); i < (int)(26); i++) c[i] += d[i] * l;
  for (int i = (int)(0); i < (int)(26); i++) c[i] = max(c[i], e[i]);
  long long cnt = 0;
  for (int i = (int)(0); i < (int)(26); i++) cnt += c[i];
  c[0] += s.size() - cnt;
  for (int i = (int)(0); i < (int)(s.size()); i++)
    if (s[i] != '?') c[s[i] - 'a']--;
  long long k = 0;
  for (int i = (int)(0); i < (int)(s.size()); i++) {
    if (s[i] == '?') {
      while (k < 26 && !c[k]) k++;
      cout << (char)(k + 'a');
      c[k]--;
    } else
      cout << s[i];
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Main();
  return 0;
}
