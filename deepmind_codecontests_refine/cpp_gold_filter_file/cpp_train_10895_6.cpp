#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chkmin(T& x, T y) {
  return x > y ? x = y, true : false;
}
template <class T>
inline bool chkmax(T& x, T y) {
  return x < y ? x = y, true : false;
}
inline long long read(void) {
  long long x, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
int n, qs, t, x, ans[100005], a[100005];
vector<pair<int, int> > q[100005];
vector<int> V;
int c(int y) {
  for (auto x : V) y = min(y, x ^ y);
  return y;
}
int main(void) {
  n = read();
  qs = read();
  t = 1;
  for (int i = (1); i <= (n); ++i) a[i] = read();
  for (int i = (1); i <= (qs); ++i)
    x = read(), q[x].push_back(make_pair(read(), i));
  for (int i = (1); i <= (n); ++i) {
    if (c(a[i]))
      V.push_back(c(a[i]));
    else
      (t *= 2) %= 1000000007;
    for (auto x : q[i]) ans[x.second] = c(x.first) ? 0 : t;
  }
  for (int i = (1); i <= (qs); ++i) printf("%d\n", ans[i]);
  return 0;
}
