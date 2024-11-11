#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, x;
vector<pair<int, int> > vl[MAXN], vr[MAXN];
vector<int> sufl[MAXN], prefr[MAXN];
int L[MAXN], R[MAXN], C[MAXN];
int main() {
  scanf("%d", &n), scanf("%d", &x);
  for (int i = 0; i < (int)n; i++) {
    int l, r, c;
    scanf("%d", &l), scanf("%d", &r);
    scanf("%d", &c);
    vl[r - l + 1].push_back({l, c});
    vr[r - l + 1].push_back({r, c});
    L[i] = l;
    R[i] = r;
    C[i] = c;
  }
  for (int xx = 0; xx < (int)MAXN; xx++) {
    sort(vl[xx].begin(), vl[xx].end());
    sort(vr[xx].begin(), vr[xx].end());
    int s = vl[xx].size();
    if (s == 0) continue;
    sufl[xx].resize(s);
    sufl[xx][s - 1] = vl[xx][s - 1].second;
    for (int i = s - 2; i > (int)-1; i--) {
      sufl[xx][i] = min(vl[xx][i].second, sufl[xx][i + 1]);
    }
    prefr[xx].resize(s);
    prefr[xx][0] = vr[xx][0].second;
    for (int i = 1; i < (int)s; i++) {
      prefr[xx][i] = min(vr[xx][i].second, prefr[xx][i - 1]);
    }
  }
  int ans = 2e9 + 5;
  for (int i = 0; i < (int)n; i++) {
    int x2 = x - (R[i] - L[i] + 1);
    if (x2 < 1 || x2 >= MAXN) continue;
    pair<int, int> tmp = {R[i], 1e9};
    int j = upper_bound(vl[x2].begin(), vl[x2].end(), tmp) - vl[x2].begin();
    if (j != vl[x2].size()) {
      ans = min(ans, C[i] + sufl[x2][j]);
    }
    tmp = {L[i], -1};
    j = lower_bound(vr[x2].begin(), vr[x2].end(), tmp) - vr[x2].begin();
    if (j != 0) {
      j--;
      ans = min(ans, C[i] + prefr[x2][j]);
    }
  }
  if (ans > 2e9)
    printf("-1\n");
  else
    printf("%d\n", ans);
}
