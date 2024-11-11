#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
void dbg(const char *fmt, ...) {}
std::vector<std::pair<int, int> > a, b;
int ans = 0;
void relax() {
  for (int i = 0; i < (int)a.size(); i++)
    for (int j = 0; j < (int)b.size(); j++) {
      int l = std::max(a[i].first, b[j].first);
      int r = std::min(a[i].second, b[j].second);
      ans = std::max(ans, r - l + 1);
    }
}
int mod;
void add(std::vector<std::pair<int, int> > &v, int l, int r) {
  if (l > r) return;
  v.push_back(std::pair<int, int>(l % mod, r % mod));
}
int main() {
  int l1, l2, r1, r2;
  scanf("%d%d", &l1, &r1);
  scanf("%d%d", &l2, &r2);
  l1--;
  r1--;
  l2--;
  r2--;
  mod = 2;
  for (int i = 0; i < 31; i++) {
    int l, r;
    l = l1 / mod * mod;
    add(a, std::max(l, l1), std::min(l + mod - 2, r1));
    l += mod;
    r += mod;
    add(a, std::max(l, l1), std::min(l + mod - 2, r1));
    l = r1 / mod * mod;
    add(a, std::max(l, l1), std::min(l + mod - 2, r1));
    l = l2 / mod * mod;
    add(b, std::max(l, l2), std::min(l + mod - 2, r2));
    l += mod;
    r += mod;
    add(b, std::max(l, l2), std::min(l + mod - 2, r2));
    l = r2 / mod * mod;
    add(b, std::max(l, l2), std::min(l + mod - 2, r2));
    relax();
    a.clear();
    b.clear();
    mod *= 2;
  }
  printf("%d\n", ans);
  return 0;
}
