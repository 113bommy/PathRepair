#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int treePr[MAXN * 4] = {0}, treeSf[MAXN * 4] = {0};
vector<stack<int>> history;
void setValSf(int pos, int l, int r, int& ind, int& val) {
  if (l == r) {
    history[ind].push(treeSf[pos]);
    treeSf[pos] = val;
    return;
  }
  int mid = (l + r) >> 1;
  int npos = pos << 1;
  if (ind <= mid)
    setValSf(npos, l, mid, ind, val);
  else
    setValSf(npos + 1, mid + 1, r, ind, val);
  treeSf[pos] = max(treeSf[npos], treeSf[npos + 1]);
}
void ctrlZSf(int pos, int l, int r, int& ind) {
  if (l == r) {
    treeSf[pos] = history[ind].top();
    history[ind].pop();
    return;
  }
  int mid = (l + r) >> 1;
  int npos = pos << 1;
  if (ind <= mid)
    ctrlZSf(npos, l, mid, ind);
  else
    ctrlZSf(npos + 1, mid + 1, r, ind);
  treeSf[pos] = max(treeSf[npos], treeSf[npos + 1]);
}
int getMaxSf(int pos, int l, int r, int ql, int qr) {
  if (l > qr || ql > r) return 0;
  if (l == ql && r == qr) return treeSf[pos];
  int mid = (l + r) >> 1;
  int npos = pos << 1;
  int val1 = getMaxSf(npos, l, mid, ql, min(mid, qr));
  int val2 = getMaxSf(npos + 1, mid + 1, r, max(mid + 1, ql), qr);
  return max(val1, val2);
}
void setValPr(int pos, int l, int r, int& ind, int& val) {
  if (l == r) {
    treePr[pos] = val;
    return;
  }
  int mid = (l + r) >> 1;
  int npos = pos << 1;
  if (ind <= mid)
    setValPr(npos, l, mid, ind, val);
  else
    setValPr(npos + 1, mid + 1, r, ind, val);
  treePr[pos] = max(treePr[npos], treePr[npos + 1]);
}
int getMaxPr(int pos, int l, int r, int ql, int qr) {
  if (l > qr || ql > r) return 0;
  if (l == ql && r == qr) return treePr[pos];
  int mid = (l + r) >> 1;
  int npos = pos << 1;
  int val1 = getMaxPr(npos, l, mid, ql, min(mid, qr));
  int val2 = getMaxPr(npos + 1, mid + 1, r, max(mid + 1, ql), qr);
  return max(val1, val2);
}
void Solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (signed i = 0; i < (n); i++) {
    cin >> a[i];
    a[i] -= i;
  }
  vector<int> b = a;
  sort((b).begin(), (b).end());
  b.resize(unique((b).begin(), (b).end()) - b.begin());
  int zN = b.size();
  vector<int> obr(zN);
  history.resize(zN);
  for (int i = 0; i < n; ++i) {
    int j = lower_bound((b).begin(), (b).end(), a[i]) - b.begin();
    obr[j] = a[i];
    a[i] = j;
  }
  for (int i = n - 1; i >= 0; --i) {
    int maxSf = getMaxSf(1, 0, zN - 1, a[i], zN - 1) + 1;
    setValSf(1, 0, zN - 1, a[i], maxSf);
  }
  int pr = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ctrlZSf(1, 0, zN - 1, a[i]);
    int ind = pr;
    if (pr != 0 && obr[pr] == obr[pr - 1] + 1) ind--;
    ans = max(ans, getMaxPr(1, 0, zN - 1, 0, pr) +
                       getMaxSf(1, 0, zN - 1, ind, zN - 1));
    int maxPr = getMaxPr(1, 0, zN - 1, 0, a[i]) + 1;
    setValSf(1, 0, zN - 1, a[i], maxPr);
    pr = a[i];
  }
  cout << n - 1 - ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Solve();
  return 0;
}
