#include <bits/stdc++.h>
using namespace std;
inline void rd(char *x) { scanf("%s", x); }
inline void rd(double &x) { scanf("%lf", &x); }
template <typename T>
inline void rd(T &x) {
  x = 0;
  bool is = 0;
  char ch = getchar();
  while (!isdigit(ch)) is |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  is && (x = -x);
}
template <typename T, typename... U>
inline void rd(T &x, U &...y) {
  rd(x), rd(y...);
}
template <typename T>
inline void write(T x) {
  if (x >= 10) write(x / 10);
  putchar('0' + x % 10);
}
const int maxn = 114514;
set<pair<int, int>> st;
inline pair<int, int> mp(int u, int v) {
  return u < v ? pair<int, int>(u, v) : pair<int, int>(v, u);
}
int ans[6], n, m;
int check() {
  int ret = 0;
  for (int i = (1), __i = (5); i <= __i; ++i)
    for (int j = (1), __j = (i - 1); j <= __j; ++j)
      if (ans[i] == ans[j]) return 0;
  for (int i = (1), __i = (5); i <= __i; ++i)
    for (int j = (1), __j = (i - 1); j <= __j; ++j)
      if (st.count(mp(ans[i], ans[j]))) ++ret;
  return (ret == 10 || ret == 0);
}
int main() {
  srand(time(0));
  rd(n, m);
  for (int i = (1), __i = (m); i <= __i; ++i) {
    int u, v;
    rd(u, v);
    st.insert(mp(u, v));
  }
  int fl = 0;
  for (int tot = (1), __tot = (514514); tot <= __tot; ++tot) {
    for (int i = (1), __i = (5); i <= __i; ++i) ans[i] = rand() % n + 1;
    if (check()) {
      fl = 1;
      break;
    }
  }
  if (!fl)
    puts("-1");
  else
    for (int i = (1), __i = (5); i <= __i; ++i) printf("%d ", ans[i]);
}
