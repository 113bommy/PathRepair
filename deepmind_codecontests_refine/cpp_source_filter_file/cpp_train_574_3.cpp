#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
template <class T>
inline void umin(T &x, T y) {
  x = x < y ? x : y;
}
template <class T>
inline void umax(T &x, T y) {
  x = x > y ? x : y;
}
inline unsigned int R() {
  static unsigned int seed = 416;
  return seed ^= seed >> 5, seed ^= seed << 17, seed ^= seed >> 13;
}
const int N = 102000, inf = 0x3f3f3f3f;
int n, k;
pair<int, int> a[N], sta[N];
int top, qz[N], buc[N * 303];
long long ans[N];
pair<int, int> s[N];
int len;
int Abs(int x) { return x > 0 ? x : -x; }
int sgn(int x) { return x > 0 ? 1 : -1; }
int main() {
  read(n);
  read(k);
  for (register int i = (1); i <= (n); i++)
    read(a[i].first), read(a[i].second),
        sta[i] = pair<int, int>(a[i].second, a[i].second + k - 1);
  sort(sta + 1, sta + n + 1);
  top = 0;
  for (register int i = (1); i <= (n); i++)
    if (!top || sta[top].second < sta[i].first)
      sta[++top] = sta[i];
    else
      umax(sta[top].second, sta[i].second);
  for (register int i = (1); i <= (top); i++)
    qz[i] = qz[i - 1] + sta[i].second - sta[i].first + 1;
  for (register int i = (1); i <= (n); i++) {
    int p =
        upper_bound(sta + 1, sta + top + 1, pair<int, int>(a[i].second, inf)) -
        sta - 1;
    a[i].second = qz[p - 1] + a[i].second - sta[p].first + 1;
  }
  for (register int i = (1); i <= (n); i++)
    s[++len] = pair<int, int>(a[i].first, i),
    s[++len] = pair<int, int>(a[i].first + k, -i);
  sort(s + 1, s + len + 1);
  for (register int i = (1); i <= (len); i++) {
    int xs = sgn(s[i].second), l = a[Abs(s[i].second)].second, p = s[i].first;
    for (register int j = (l); j <= (l + k - 1); j++)
      ans[buc[j]] -= inf - p, ans[buc[j] += xs] += inf - p;
  }
  for (register int i = (1); i <= (n); i++) printf("%lld ", ans[i]);
  return 0;
}
