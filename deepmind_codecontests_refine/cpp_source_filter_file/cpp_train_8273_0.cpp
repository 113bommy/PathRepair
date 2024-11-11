#include <bits/stdc++.h>
using namespace std;
const int maxn = 710 * 710;
multiset<long long> s[710];
long long a[maxn], val[710];
int n, q, nn;
void build() {
  for (int i = 0; i < q; i++)
    for (int j = i * q; j < (i + 1) * q && j < nn; j++) s[i].insert(a[j]);
}
void increase(int l, int r, long long v) {
  bool flag = false;
  for (int i = 0; i < q && flag; i++) {
    int l2 = i * q, r2 = min(nn - 1, (i + 1) * q - 1);
    if (l2 >= l && r2 <= r)
      val[i] += v;
    else if (!(l2 > r || l > r)) {
      for (int j = max(l2, l); j <= r2 && j <= r; j++) {
        s[i].erase(s[i].find(a[j]));
        a[j] += v;
        s[i].insert(a[j]);
      }
    } else if (l2 > r)
      flag = true;
  }
}
long long get_ans(long long y) {
  long long right = -1, left = -1, mo = -1;
  for (int i = 0; i < q && right == -1; i++) {
    int l = (i * q), r = (i + 1) * q - 1;
    if (s[i].find(y - val[i]) != s[i].end()) {
      for (int j = l; j <= r && right == -1; j++)
        if (a[j] == y - val[i]) right = j;
    }
  }
  for (int i = q - 1; i >= 0 && left == -1; i--) {
    int l = (i * q), r = (i + 1) * q - 1;
    if (s[i].find(y - val[i]) != s[i].end()) {
      for (int j = min(nn, r); j >= l && left == -1; j--)
        if (a[j] == y - val[i]) left = j;
    }
  }
  if (left == mo || right == mo)
    return mo;
  else
    return left - right;
}
int main() {
  int que;
  scanf("%d", &n);
  scanf("%d", &que);
  q = sqrt(n) + 1;
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
  nn = n;
  n = q * q;
  build();
  while (que--) {
    int type;
    scanf("%d", &type);
    if (type & 1) {
      long long v;
      int l, r;
      scanf("%d", &l);
      scanf("%d", &r);
      scanf("%I64d", &v);
      l--, r--;
      increase(l, r, v);
    } else {
      long long y;
      scanf("%I64d", &y);
      printf("%I64d \n", get_ans(y));
    }
  }
  return 0;
}
