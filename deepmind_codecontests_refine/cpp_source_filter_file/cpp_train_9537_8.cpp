#include <bits/stdc++.h>
using namespace std;
string itos(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
int n, q, a[300010];
vector<int> cnt[300010];
static unsigned long x = 123456789, y = 362436069, z = 521288629;
unsigned long xorshf96(void) {
  unsigned long t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}
int getRand(int mi, int mx) {
  int mod = mx - mi + 1;
  return xorshf96() % mod + mi;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]].push_back((i));
  }
  int l, r, k, c, res = 2147483647;
  set<int> s;
  while (q--) {
    res = 2147483647;
    s.clear();
    scanf("%d%d%d", &l, &r, &k);
    k = (r - l + 1) / k + 1;
    for (int i = 0, x; i < 60; i++) {
      x = a[getRand(l - 1, r - 1)];
      int pos =
          lower_bound(cnt[x].begin(), cnt[x].end(), l - 1) - cnt[x].begin();
      if (pos + k - 1 < cnt[x].size() && cnt[x][pos + k - 1] < r)
        res = min(res, x);
    }
    printf("%d\n", res == 2147483647 ? -1 : res);
  }
  return 0;
}
