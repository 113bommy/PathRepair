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
vector<pair<long long, long long> > a, b;
int stk[SIZE], sn;
vector<int> ans;
int main() {
  int n;
  R(n);
  for (int i = (1); i <= (n); ++i) {
    long long x;
    R(x);
    a.push_back({x, i});
  }
  for (int i = (1); i <= (n); ++i) {
    long long x;
    R(x);
    b.push_back({x, i});
  }
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end());
  {
    long long v = 0;
    for (int i = 0; i < (n); ++i) {
      v += b[i].first - a[i].first;
      if (v < 0) {
        W("NO");
        return 0;
      }
    }
    if (v) {
      W("NO");
      return 0;
    }
  }
  W("YES");
  for (int i = 0; i < (n); ++i) {
    if (a[i].first == b[i].first) continue;
    if (b[i].first - a[i].first > 0) {
      stk[sn++] = i;
    } else if (b[i].first - a[i].first < 0) {
      while (b[i].first - a[i].first < 0) {
        int id = stk[sn - 1];
        long long v = min(a[i].first - b[i].first, b[id].first - a[id].first);
        ans.push_back(a[id].second);
        ans.push_back(a[i].second);
        ans.push_back(v);
        a[id].first += v;
        a[i].first -= v;
        if (b[id].first == a[id].first) sn--;
      }
    }
  }
  W(((int)(ans).size()) / 3);
  for (int i = 0; i < (((int)(ans).size())); ++i) {
    W(ans[i], ans[i + 1], ans[i + 2]);
    i += 2;
  }
  return 0;
}
