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
const int SIZE = 2e6 + 10;
vector<int> AA;
struct Union_Find {
  int d[SIZE], num[SIZE], cc[SIZE];
  void init(int n) {
    for (int i = 0; i < (n); ++i) d[i] = i, num[i] = 1, cc[i] = 0;
  }
  int find(int x) { return (x != d[x]) ? (d[x] = find(d[x])) : x; }
  bool is_root(int x) { return d[x] == x; }
  int uu(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return x;
    if (num[x] > num[y]) swap(x, y);
    num[y] += num[x];
    cc[y] += cc[x];
    d[x] = y;
    return y;
  }
} U;
int a[SIZE], b[SIZE];
bool good(int n, int v) {
  U.init(v + 1);
  for (int i = 0; i < (n); ++i) {
    if (a[i] > v && b[i] > v) return 0;
    if (a[i] > v) {
      int x = U.find(a[i]);
      U.cc[x]++;
      if (U.cc[x] > U.num[x]) return 0;
    } else if (a[i] > v) {
      int x = U.find(b[i]);
      U.cc[x]++;
      if (U.cc[x] > U.num[x]) return 0;
    } else {
      int x = U.uu(a[i], b[i]);
      U.cc[x]++;
      if (U.cc[x] > U.num[x]) return 0;
    }
  }
  return 1;
}
int main() {
  int n;
  R(n);
  for (int i = 0; i < (n); ++i) {
    R(a[i], b[i]);
    AA.push_back(a[i]);
    AA.push_back(b[i]);
  }
  (sort(AA.begin(), AA.end()),
   AA.resize(distance(AA.begin(), unique(AA.begin(), AA.end()))));
  for (int i = 0; i < (n); ++i) {
    a[i] = (lower_bound(AA.begin(), AA.end(), a[i]) - AA.begin());
    b[i] = (lower_bound(AA.begin(), AA.end(), b[i]) - AA.begin());
  }
  int ll = 0, rr = ((int)(AA).size());
  while (ll < rr) {
    int mm = (ll + rr) / 2;
    if (good(n, mm))
      rr = mm;
    else
      ll = mm + 1;
  }
  if (ll == ((int)(AA).size()))
    W(-1);
  else
    W(AA[ll]);
  return 0;
}
