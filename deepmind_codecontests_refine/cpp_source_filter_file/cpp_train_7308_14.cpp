#include <bits/stdc++.h>
using namespace std;
const int N = 210000;
int n, a[N], pos[N], tree[N];
set<int> app;
template <class T>
inline void read(T &x) {
  x = 0;
  char ch = getchar(), w = 0;
  while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = w ? -x : x;
  return;
}
inline void modify(int x, int w) {
  while (x <= n) tree[x] += w, x += x & -x;
  return;
}
inline int query(int x) {
  int ret = 0;
  while (x) ret += tree[x], x -= x & -x;
  return ret;
}
int main() {
  read(n);
  for (register int i = 1; i <= n; ++i) read(a[i]), pos[a[i]] = i;
  modify(pos[1], 1), app.insert(pos[1]);
  long long sum1 = 0, sum2 = 0;
  printf("0 ");
  for (register int i = 2, mid = pos[1], lt = 0, rt = 0; i <= n; ++i) {
    int num = query(pos[i]);
    sum2 += i - num - 1, app.insert(pos[i]), modify(pos[i], 1);
    if (num >= i >> 1)
      ++rt, sum1 += pos[i] - mid + (i >> 1) - i;
    else
      ++lt, sum1 += mid - pos[i] - (i >> 1);
    if (lt > rt) {
      auto it = --app.lower_bound(mid);
      sum1 -= (mid - *it - 1) * (lt - rt), mid = *it, --lt, ++rt;
    }
    if (lt < rt - 1) {
      auto it = app.upper_bound(mid);
      sum1 -= (*it - mid - 1) * (rt - lt), mid = *it, ++lt, --rt;
    }
    printf("%lld ", sum1 + sum2);
  }
  return 0;
}
