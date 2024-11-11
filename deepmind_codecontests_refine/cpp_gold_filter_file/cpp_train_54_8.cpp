#include <bits/stdc++.h>
using namespace std;
int same[100100];
int tree[100100];
int m;
void add(int v) {
  while (v <= m) {
    tree[v]++;
    v += (v & (v ^ (v - 1)));
  }
}
int query(int v) {
  int ret = 0;
  while (v > 0) {
    ret += tree[v];
    v -= (v & (v ^ (v - 1)));
  }
  return ret;
}
int rev(int v) {
  int ret = 0;
  while (v) {
    ret = ret * 10 + v % 10;
    v /= 10;
  }
  return ret;
}
int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int beg, end, mid, n, i, j, k, x, w, top = 0;
  pair<long long, int> ret = make_pair(100000000000LL, -1);
  scanf("%d %d %d", &n, &m, &w);
  end = m;
  for (i = 1; i <= m; i++)
    if (i == rev(i)) same[top++] = i;
  for (i = 1; i <= n; i++) {
    x = rev(i);
    k = x / gcd(x, i);
    if (x == i)
      for (j = 0; j < top; j++) add(same[j]);
    else
      for (j = k; j <= m; j += k)
        if (1LL * i * j == 1LL * x * rev(j)) add(j);
    beg = 0;
    while (beg < end) {
      mid = (beg + end) / 2;
      if (query(mid) < w)
        beg = mid + 1;
      else
        end = mid;
    }
    if (query(beg) >= w) ret = min(ret, make_pair(1LL * i * beg, i));
  }
  if (ret.second == -1)
    printf("-1\n");
  else
    printf("%d %d\n", ret.second, ret.first / ret.second);
  return 0;
}
