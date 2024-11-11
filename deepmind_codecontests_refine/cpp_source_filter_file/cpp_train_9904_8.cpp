#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 7;
int n, m, a[N], l[N], r[N], b[N], c[N] = {0}, vis[N];
int mxindex, ans = -1;
void getmax(int i) {
  for (int j = 1; j <= n; ++j) b[j] = a[j], c[j] = 0;
  for (int j = 1; j <= m; ++j) {
    if (r[j] < i || l[j] > i) {
      c[l[j]] -= 1;
      c[r[j] + 1] += 1;
    }
  }
  int mn = b[1];
  for (int j = 1; j <= n; ++j) {
    c[j] += c[j - 1], b[j] += c[j], mn = min(mn, b[j]);
  }
  if (a[i] - mn > ans) {
    ans = a[i] - mn;
    mxindex = i;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &l[i], &r[i]);
    vis[l[i]] = vis[r[i]] = 1;
  }
  vector<int> vs;
  for (int i = 1; i <= n; ++i)
    if (vis[i]) vs.push_back(i);
  vs.push_back(1);
  vs.push_back(n);
  sort(vs.begin(), vs.end());
  vs.erase(unique(vs.begin(), vs.end()), vs.end());
  for (int v : vs) getmax(v);
  int mxv, mxid;
  for (int i = 0; i < vs.size() - 1; ++i) {
    if (vs[i] + 1 == vs[i + 1]) continue;
    mxv = a[vs[i] + 1], mxid = vs[i + 1];
    for (int j = vs[i] + 1; j < vs[i + 1]; ++j) {
      if (a[j] > mxv) mxv = a[j], mxid = j;
    }
    getmax(mxid);
  }
  vector<int> ansv;
  for (int i = 1; i <= m; ++i) {
    if (r[i] < mxindex || l[i] > mxindex) {
      ansv.push_back(i);
    }
  }
  cout << ans << endl << ansv.size() << endl;
  for (int i = 0; i < ansv.size(); ++i) {
    printf("%d%c", ansv[i], i == ansv.size() - 1 ? '\n' : ' ');
  }
  if (ansv.size() == 0) puts("");
  return 0;
}
