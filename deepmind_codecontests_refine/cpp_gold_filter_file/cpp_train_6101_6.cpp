#include <bits/stdc++.h>
using namespace std;
int n, k, x, N;
string s[100005];
vector<int> pos[100005];
int ans[2000006];
vector<pair<int, int> > yo;
bool tree[10000007];
void update(int p, int b, int e, int l) {
  if (b > e || b > l || e < l) return;
  if (b == e)
    tree[p] = true;
  else {
    int mid = (b + e) / 2;
    update(2 * p, b, mid, l);
    update(2 * p + 1, mid + 1, e, l);
    tree[p] = tree[2 * p] & tree[2 * p + 1];
  }
}
int query(int p, int b, int e, int l, int r) {
  if (b > e || b > r || e < l) return -1;
  if (b == e) {
    return b;
  }
  int mid = (b + e) / 2;
  int ret = -1;
  if (tree[2 * p] == false) ret = query(2 * p, b, mid, l, r);
  if (ret > 0) return ret;
  if (tree[2 * p + 1] == false) ret = query(2 * p + 1, mid + 1, e, l, r);
  return ret;
}
int main() {
  memset(ans, -1, sizeof(ans));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int sz = s[i].size();
    yo.push_back(make_pair(sz, i));
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &x);
      pos[i].push_back(x);
      N = max(N, x + sz - 1);
    }
  }
  sort(yo.begin(), yo.end());
  for (int i = yo.size() - 1; i > -1; i--) {
    int id = yo[i].second;
    x = pos[id].size();
    for (int j = 0; j < x; j++) {
      int ss = pos[id][j];
      int lo, hi;
      lo = ss, hi = ss + s[id].size() - 1;
      lo = query(1, 1, N, lo, hi);
      if (lo != -1) {
        for (int ii = lo; ii <= hi; ii++) {
          if (ans[ii] != -1) {
            hi = ii;
            break;
          }
          ans[ii] = s[id][ii - ss] - 'a';
          update(1, 1, N, ii);
        }
      }
    }
  }
  for (int i = 1; i <= N; i++)
    if (ans[i] == -1) ans[i] = 0;
  for (int i = 1; i <= N; i++) printf("%c", ans[i] + 'a');
  return 0;
}
