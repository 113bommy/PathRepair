#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 100010;
long long query, h;
struct node {
  long long l, r;
  bool operator<(const node &rhs) const {
    if (l == rhs.l) return r > rhs.r;
    return l < rhs.l;
  }
} a[N];
vector<node> v;
int main() {
  while (~scanf("%lld%lld", &h, &query)) {
    v.clear();
    long long le, l, r, f, cnt = 0;
    bool cheat = 0;
    long long L = (1LL << (h - 1)), R = (1LL << h) - 1;
    while (query--) {
      scanf("%lld%lld%lld%lld", &le, &l, &r, &f);
      if (cheat) continue;
      l = l * (1 << (h - le));
      r = (r + 1) * (1 << (h - le)) - 1;
      if (f) {
        if (l > R || r < L) {
          cheat = 1;
          continue;
        } else {
          L = max(L, l);
          R = min(R, r);
        }
      } else {
        node tmp;
        tmp.l = l, tmp.r = r;
        a[++cnt] = tmp;
      }
    }
    if (cheat) {
      puts("Game cheated!");
      continue;
    }
    sort(a + 1, a + cnt + 1);
    f = 1;
    for (int i = 1; i <= cnt; ++i) {
      long long l = a[i].l, r = a[i].r;
      if (L > R) {
        f = 0;
        break;
      }
      if (l > R) break;
      if (r < L) continue;
      if (l <= L && R <= r) {
        f = 0;
        break;
      }
      if (L <= l && r <= R) {
        node tmp;
        tmp.l = L, tmp.r = l - 1;
        if (tmp.l <= tmp.r) v.push_back(tmp);
        L = r + 1;
        continue;
      }
      if (L <= l && R <= r) {
        node tmp;
        tmp.l = L, tmp.r = l - 1;
        if (tmp.l <= tmp.r) v.push_back(tmp);
        f = 0;
        break;
      }
      if (l <= L && r <= R) L = r + 1;
    }
    if (L <= R && f) {
      node tmp;
      tmp.l = L, tmp.r = R;
      v.push_back(tmp);
    }
    int sz = v.size();
    if (sz == 0)
      puts("Game cheated!");
    else if (sz >= 2 || (sz == 1 && v[0].r > v[0].l))
      puts("Data not sufficient!");
    else
      printf("%lld\n", v[0].l);
  }
  return 0;
}
