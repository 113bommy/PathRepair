#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int maxn = 123457;
int n, m, dd, ans, ccm = -1;
int atk[maxn];
vector<int> ar[maxn];
int ff(int nn, int pr = -1, int di = 0) {
  int r = 0;
  if (atk[nn] && di > ccm || (di == ccm && nn < ans)) {
    ccm = di;
    ans = nn;
  }
  if (atk[nn]) r = di;
  for (int i = 0; i < ar[nn].size(); ++i) {
    int nxt = ar[nn][i];
    if (nxt == pr) continue;
    int v = ff(nxt, nn, di + 1);
    if (v != 0) dd++;
    r = max(r, v);
  }
  return r;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ar[a].push_back(b);
    ar[b].push_back(a);
  }
  int l = 1;
  int aa;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &aa);
    atk[aa] = 1;
  }
  l = aa;
  ff(l);
  ccm = -1;
  dd = 0;
  int ans1 = ans;
  ans = l;
  int m = ff(ans1);
  ans = min(ans, ans1);
  cout << ans << endl;
  cout << (2 * dd - m);
}
