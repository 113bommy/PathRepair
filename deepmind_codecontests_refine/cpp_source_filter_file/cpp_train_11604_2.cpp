#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int ver[100005];
vector<int> ed[100005];
int ans = 1;
int inv(int b) {
  return (b == 1) ? 1 : 1ll * inv(mod % b) * (mod - mod / b) % mod;
}
void go(int wh, int p, int& adot, int& non) {
  int i1;
  int dottmp, nontmp;
  vector<int> vdot, vnon;
  non = 1;
  for (i1 = 0; i1 < ed[wh].size(); i1++) {
    if (ed[wh][i1] != p) {
      go(ed[wh][i1], wh, dottmp, nontmp);
      vdot.push_back(dottmp);
      vnon.push_back(nontmp);
      non = 1ll * non * nontmp % mod;
    }
  }
  adot = 0;
  for (i1 = vdot.size() - 1; i1 >= 0; i1--) {
    adot = (adot + 1ll * non * vdot[i1] % mod * inv(vnon[i1])) % mod;
  }
  if (ver[wh] == 1) {
    ans = ans * non % mod;
    adot = 1;
    non = 1;
  } else {
    non = (non + adot) % mod;
  }
}
int main() {
  int i1;
  int n;
  int u;
  int dottmp, nontmp;
  scanf("%d", &n);
  for (i1 = 1; i1 < n; i1++) {
    scanf("%d", &u);
    ed[u].push_back(i1);
    ed[i1].push_back(u);
  }
  for (i1 = 0; i1 < n; i1++) {
    scanf("%d", &ver[i1]);
  }
  go(n - 1, -1, dottmp, nontmp);
  ans = ans * dottmp % mod;
  printf("%d\n", ans);
  return 0;
}
