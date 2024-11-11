#include <bits/stdc++.h>
const int N = 2e5 + 9;
using ll = long long;
using namespace std;
struct Node {
  ll x;
  char s[3];
  bool operator<(const Node b) const { return x < b.x; }
} e[N];
int n, pr, pb, pp, mr, mb;
ll ans;
bool jb, jp, jr;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld%s", &e[i].x, e[i].s);
  }
  sort(e, e + n);
  for (int i = 0; i < n; i++) {
    int x = e[i].x;
    if (e[i].s[0] == 'R' || e[i].s[0] == 'P') {
      if (jr) {
        ans += x - pr;
        mr = max(mr, x - pr);
      }
      pr = x;
      jr = 1;
    }
    if (e[i].s[0] == 'B' || e[i].s[0] == 'P') {
      if (jb) {
        ans += x - pb;
        mb = max(mb, x - pb);
      }
      pb = x;
      jb = 1;
    }
    if (e[i].s[0] == 'P') {
      if (jp) ans += min(0, x - pp - mr - mb);
      mr = mb = 0;
      pp = x;
      jp = 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
