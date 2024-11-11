#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1e6 + 10;
int main() {
  int n;
  R(n);
  vector<pair<int, int> > AA;
  vector<int> an(n);
  for (int i = 0; i < (n); ++i) {
    int x;
    R(x);
    AA.push_back({n - x, i});
  }
  sort((AA).begin(), (AA).end());
  int now = 1;
  for (int i = 0, j; i < n; i = j) {
    for (j = i + 1; j < n && AA[j].first == AA[i].first; j++)
      ;
    if ((j - i) % AA[i].first) {
      W("Impossible");
      return 0;
    }
    for (j = i; j < n && AA[j].first == AA[i].first; j++) {
      an[AA[j].second] = now + (j - i) / AA[i].first;
    }
    now += (j - i) / AA[i].first;
  }
  W("Possible");
  W(an);
  return 0;
}
