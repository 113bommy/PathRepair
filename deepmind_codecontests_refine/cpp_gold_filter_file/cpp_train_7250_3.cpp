#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int oo = ~0u >> 2, mo = (int)1e9 + 7;
const int mn = 8;
int a[mn];
int n;
struct rec {
  int l, b, k, x;
  rec() {}
  rec(int _l, int _b, int _k, int _x) { l = _l, b = _b, k = _k, x = _x; }
};
vector<rec> Now, Ans;
void dfs(int p) {
  if (p == ((int)(Ans).size()) + 1) return;
  if (a[p] == n) {
    Ans = Now;
    return;
  }
  for (int b = 0; b <= p; ++b)
    for (int x = 1; x <= p; ++x)
      for (int k = 1; k <= 8; k *= 2) {
        int t = a[b] + k * a[x];
        if (t <= a[p]) continue;
        Now.push_back(rec(p + 1, b, k, x));
        a[p + 1] = t;
        dfs(p + 1);
        a[p + 1] = 0;
        Now.pop_back();
        if (p >= ((int)(Ans).size())) return;
      }
}
int main() {
  cin >> n;
  Ans.resize(6);
  a[1] = 1;
  dfs(1);
  printf("%d\n", ((int)(Ans).size()));
  for (int i = 0; i <= ((int)(Ans).size()) - 1; ++i) {
    printf("lea e%cx, [", Ans[i].l + 'a' - 1);
    if (Ans[i].b) printf("e%cx + ", Ans[i].b + 'a' - 1);
    printf("%d*e%cx]\n", Ans[i].k, Ans[i].x + 'a' - 1);
  }
}
