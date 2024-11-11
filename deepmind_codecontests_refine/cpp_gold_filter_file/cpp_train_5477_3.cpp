#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 201000;
vector<int> bi[N];
int siz[N];
int val, mid1, mid2;
void dfs1(int t, int f = 0) {
  siz[t] = 1;
  int mxc = 0;
  for (int i = 0; i < bi[t].size(); ++i)
    if (bi[t][i] != f) {
      dfs1(bi[t][i], t);
      siz[t] += siz[bi[t][i]];
      if (siz[bi[t][i]] > mxc) mxc = siz[bi[t][i]];
    }
  mxc = max(mxc, n - siz[t]);
  if (mxc < val)
    val = mxc, mid1 = t, mid2 = 0;
  else if (mxc == val)
    mid2 = t;
}
vector<int> X, Y, Y_;
void ADD(int x, int y, int y_) {
  X.push_back(x);
  Y.push_back(y);
  Y_.push_back(y_);
}
int nwm, nwc, tar;
void dfs2(int t, int f) {
  int cnt = 0;
  for (int i = 0; i < bi[t].size(); ++i)
    if (bi[t][i] != f) dfs2(bi[t][i], t), cnt++;
  if (f != tar && t != tar) ADD(nwm, nwc, t), ADD(t, f, tar), nwc = t;
}
void solve(int mid1, int mid2) {
  nwm = mid1;
  for (int i = 0; i < bi[mid1].size(); ++i)
    if (bi[mid1][i] != mid2) {
      tar = nwc = bi[mid1][i];
      dfs2(bi[mid1][i], mid1);
      if (nwc != tar) ADD(nwm, nwc, tar);
    }
}
int main() {
  cin >> n;
  if (n <= 3) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    bi[a].push_back(b);
    bi[b].push_back(a);
  }
  val = n;
  dfs1(1);
  solve(mid1, mid2);
  solve(mid2, mid1);
  cout << X.size() << endl;
  for (int i = 0; i < X.size(); ++i)
    cout << X[i] << " " << Y[i] << " " << Y_[i] << endl;
}
