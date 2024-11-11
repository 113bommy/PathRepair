#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30) - 1;
const long long linf = (1ll << 62) - 1;
int q;
map<int, long long> parent, value;
inline int getLevel(long long x) {
  int ans = 0;
  while (x > 1) {
    x >>= 1;
    ans++;
  }
  return ans;
}
int main() {
  cin >> q;
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1 || t == 2) {
      long long v, k;
      scanf("%lld%lld", &v, &k);
      int level = getLevel(v);
      if (t == 1) {
        value[level] = (value[level] + k + (1ll << level)) % (1ll << level);
      } else {
        parent[level] = (parent[level] + k + (1ll << level)) % (1ll << level);
      }
    } else {
      long long v;
      scanf("%lld", &v);
      int level = getLevel(v);
      long long start = (1ll << level);
      v = (v - start - value[level] + (2ll << level)) % (1ll << level) + start;
      for (int j = level; j >= 0; j--) {
        long long start = (1ll << j);
        printf("%lld ",
               (v - start - value[j] + (2ll << j)) % (1ll << j) + start);
        v = (v - start - parent[j] + (2ll << j)) % (1ll << j) + start;
        v >>= 1;
      }
      puts("");
    }
  }
  return 0;
}
