#include <bits/stdc++.h>
using namespace std;
int payoff[200005];
int a[200005], ret[200005];
vector<pair<int, int>> query[200005];
std::vector<int> ptimes;
int tree[1000000];
void construct(int node, int lo, int hi) {
  if (lo == hi) {
    tree[node] = payoff[lo];
    return;
  }
  int Left = 2 * node;
  int Right = Left + 1;
  int mid = (lo + hi) >> 1;
  construct(Left, lo, mid);
  construct(Right, mid + 1, hi);
  tree[node] = max(tree[Left], tree[Right]);
}
int queryyyy(int node, int lo, int hi, int i, int j) {
  if (i > hi || j < lo) return 0;
  if (i <= lo && j >= hi) return tree[node];
  int left = 2 * node;
  int right = left + 1;
  int mid = (lo + hi) >> 1;
  int xx = queryyyy(left, lo, mid, i, j);
  int yy = queryyyy(right, mid + 1, hi, i, j);
  return max(xx, yy);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int q;
  cin >> q;
  int maxVal = 0;
  for (int i = 1; i <= q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int idx, x;
      scanf("%d %d", &idx, &x);
      query[idx].push_back(make_pair(i, x));
    } else {
      int x;
      scanf("%d", &x);
      ptimes.push_back(i);
      payoff[i] = x;
      maxVal = max(maxVal, x);
    }
  }
  construct(1, 1, n);
  for (int people = 1; people <= n; people++) {
    int cur = a[people];
    if (query[people].size() == 0 && ptimes.size() == 0) {
      ret[people] = cur;
    } else if (query[people].size() == 0) {
      ret[people] = max(cur, maxVal);
    } else if (ptimes.size() == 0) {
      auto it = query[people].back();
      ret[people] = it.second;
    } else {
      auto it = query[people].back();
      ret[people] = it.second;
      int last = it.second;
      int last2 = queryyyy(1, 1, n, it.first, q);
      ret[people] = max(last, last2);
    }
  }
  for (int i = 1; i <= n; i++) cout << ret[i] << " ";
  cout << endl;
}
