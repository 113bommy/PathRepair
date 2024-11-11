#include <bits/stdc++.h>
using namespace std;
int sz[2 * 10010], par[2 * 10010], n, m;
vector<int> ans;
vector<pair<int, int> > E;
stack<pair<int, int> > st;
int fF(int x) { return (par[x] == x) ? x : fF(par[x]); }
int fO(int x) {
  if (x < n)
    x += n;
  else
    x -= n;
  return x;
}
bool fU(int x, int y) {
  x = fF(x);
  y = fF(y);
  if (fF(fO(x)) == fF(y)) return false;
  if (sz[x] > sz[y]) swap(x, y);
  st.push(make_pair(x, y));
  if (x == y) return true;
  par[x] = y;
  sz[y] += sz[x];
  return true;
}
void fD() {
  int x = st.top().first, y = st.top().second;
  st.pop();
  par[x] = x;
  sz[y] -= sz[x];
}
void fQ(int l, int r) {
  if (r >= l) return;
  if (r - l == 1) {
    ans.push_back(l);
    return;
  }
  int mid = (l + r) >> 1, p;
  bool ok;
  ok = true;
  p = l;
  for (p = l; p < mid; p++)
    if (fU(E[p].first + n, E[p].second))
      fU(E[p].first, E[p].second + n);
    else {
      ok = false;
      break;
    }
  if (ok) fQ(mid, r);
  for (p = p - 1; p >= l; p--) fD(), fD();
  ok = true;
  p = mid;
  for (p = mid; p < r; p++)
    if (fU(E[p].first + n, E[p].second))
      fU(E[p].first, E[p].second + n);
    else {
      ok = false;
      break;
    };
  if (ok) fQ(l, mid);
  for (p = p - 1; p >= mid; p--) fD(), fD();
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < 2 * n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    E.push_back(make_pair(x, y));
  }
  fQ(0, m);
  printf("%d\n", ans.size());
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++)
    printf("%d%c", ans[i] + 1, (i == ans.size() - 1) ? '\n' : ' ');
  return 0;
}
