#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 200000;
const int MAXM = MAXN - 1;
int n;
int ghead[MAXN], gnxt[2 * MAXM], gto[2 * MAXM];
int deg[MAXN], dead[MAXN];
vector<int> todo[MAXN];
int q[MAXN], qhead, qtail;
int solve() {
  qhead = qtail = 0;
  for (int i = (0); i < (n); ++i)
    if (deg[i] == 1) q[qhead++] = i;
  int nedge = n - 1;
  int root = -1;
  while (qtail < qhead) {
    int at = q[qtail++];
    int par = -1;
    for (int x = ghead[at]; x != -1; x = gnxt[x]) {
      int to = gto[x];
      if (dead[to]) continue;
      assert(par == -1);
      par = to;
    }
    if (par == -1) {
      if (root != -1) return -1;
      root = at;
      continue;
    } else {
      int ntodo;
      if (((int)(todo[at]).size()) == 0) {
        ntodo = 1;
      } else {
        int fst = todo[at][0];
        bool now = true;
        for (int i = (0); i < (((int)(todo[at]).size())); ++i)
          if (todo[at][i] != fst) now = false;
        if (!now) {
          if (root != -1) return -1;
          root = at;
          continue;
        }
        nedge -= (((int)(todo[at]).size()) - 1) * fst;
        ntodo = fst + 1;
      }
      dead[at] = true;
      todo[par].push_back(ntodo);
      if (--deg[par] == 1) q[qhead++] = par;
    }
  }
  if (root != -1 && ((int)(todo[root]).size()) >= 3) {
    sort(todo[root].begin(), todo[root].end());
    int mn = todo[root][0], mx = todo[root].back(),
        cnt = ((int)(todo[root]).size());
    if (mn == mx) {
      nedge -= (cnt - 2) * mn;
    } else {
      int mncnt = 0, mxcnt = 0;
      for (int i = (0); i < (((int)(todo[root]).size())); ++i)
        if (todo[root][i] == mn)
          ++mncnt;
        else if (todo[root][i] == mx)
          ++mxcnt;
        else
          return -1;
      nedge -= (mncnt - 1) * mx;
      nedge -= (mxcnt - 1) * mn;
    }
  }
  while (nedge % 2 == 0) nedge /= 2;
  return nedge;
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i)
    ghead[i] = -1, deg[i] = 0, dead[i] = false, todo[i].clear();
  for (int i = (0); i < (n - 1); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    gnxt[2 * i + 0] = ghead[a], ghead[a] = 2 * i + 0, gto[2 * i + 0] = b,
                 ++deg[a];
    gnxt[2 * i + 1] = ghead[b], ghead[b] = 2 * i + 1, gto[2 * i + 1] = a,
                 ++deg[b];
  }
  printf("%d\n", solve());
}
int main() {
  run();
  return 0;
}
