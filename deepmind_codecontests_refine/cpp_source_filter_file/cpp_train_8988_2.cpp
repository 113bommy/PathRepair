#include <bits/stdc++.h>
using namespace std;
int rt[222222], lf[222222], n, pk[222222];
int dis(int st) {
  if (st == 1 && rt[st] == n)
    return 1 << 29;
  else if (st == 1)
    return rt[st] - 1;
  else if (rt[st] == n)
    return rt[st] - st - 1;
  else {
    int pos = (rt[st] + st) / 2;
    return pos - st;
  }
}
struct comp {
  bool operator()(const int &a, const int &b) const {
    int sa = dis(a), sb = dis(b);
    if (sa == sb) return a < b;
    return sa > sb;
  }
};
set<int, comp> T;
map<int, int> mp;
int main() {
  memset(lf, -1, sizeof(lf));
  memset(rt, -1, sizeof(rt));
  memset(pk, 0, sizeof(pk));
  int k;
  scanf("%d%d", &n, &k);
  rt[1] = n;
  lf[n] = 1;
  T.insert(1);
  for (int i = (0); i < (k); i++) {
    int op, id;
    scanf("%d%d", &op, &id);
    if (op == 1) {
      int l = *T.begin();
      int r = rt[l];
      int pos = -1;
      if (l == 1 && r == n)
        pos = 1;
      else if (l == 1)
        pos = 1;
      else if (r == n)
        pos = n;
      else
        pos = (l + r) / 2;
      pk[pos] = 1;
      mp[id] = pos;
      T.erase(T.begin());
      if (pos > l) {
        rt[l] = pos - 1;
        lf[pos - 1] = l;
        T.insert(l);
      }
      if (pos < r) {
        rt[pos + 1] = r;
        lf[r] = pos + 1;
        T.insert(pos + 1);
      }
      printf("%d\n", pos);
    } else {
      int x = mp[id];
      int l = x, r = x;
      if (x > 1 && !pk[x - 1]) {
        l = lf[x - 1];
        T.erase(l);
        lf[x - 1] = -1;
        rt[l] = -1;
      }
      if (x < n && !pk[x + 1]) {
        if (T.find(x + 1) == T.end()) puts("asdf");
        T.erase(x + 1);
        r = rt[x + 1];
        lf[r] = -1;
        rt[x + 1] = -1;
      }
      rt[l] = r;
      lf[r] = l;
      T.insert(l);
      mp.erase(id);
      pk[x] = 0;
    }
  }
  return 0;
}
