#include <bits/stdc++.h>
using namespace std;
using tu2 = pair<long long, int>;
const int MAX = 1 << 18;
const int MAXNODES = MAX * 2;
tu2 seg[MAXNODES][5];
long long lazy[MAXNODES][5];
bool cmd(tu2 a, tu2 b) { return a.first < b.first; }
void putLazy(int t, int root, bool isLeaf) {
  seg[root][t].first += lazy[root][t];
  if (!isLeaf) {
    lazy[(root << 1)][t] += lazy[root][t];
    lazy[((root << 1) + 1)][t] += lazy[root][t];
  }
  lazy[root][t] = 0;
}
tu2 query(int t, int x, int st = 0, int en = MAX - 1, int root = 1) {
  putLazy(t, root, st == en);
  if (st > x) return tu2(-(1LL << 60), MAX - 1);
  if (x >= en) return seg[root][t];
  return max(query(t, x, st, ((st + en) >> 1), (root << 1)),
             query(t, x, (((st + en) >> 1) + 1), en, ((root << 1) + 1)), cmd);
}
tu2 update(int t, int x, int y, long long first, int st = 0, int en = MAX - 1,
           int root = 1) {
  putLazy(t, root, st == en);
  if (x > en || y < st) return seg[root][t];
  if (st >= x && en <= y) {
    lazy[root][t] += first;
    putLazy(t, root, st == en);
    if (st == en) seg[root][t].second = st;
    return seg[root][t];
  }
  return seg[root][t] =
             max(update(t, x, y, first, st, ((st + en) >> 1), (root << 1)),
                 update(t, x, y, first, (((st + en) >> 1) + 1), en,
                        ((root << 1) + 1)),
                 cmd);
}
int arr[MAX], n, k, b, c;
long long ans[MAX][5];
int main() {
  cin >> n >> k >> b >> c;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) update(j, i, i, 0);
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
  sort(arr, arr + n);
  long long tot = (1LL << 60);
  for (int j = 0; j < 5; j++) {
    long long add = (j - arr[k - 1] % 5 + 5) % 5 * c;
    long long temp1 = arr[k - 1] + add / c;
    ans[k - 1][j] = add;
    update(j, k - 1, k - 1, add);
    for (int i = 0; i < k - 1; i++) {
      long long add = (j - arr[i] % 5 + 5) % 5 * c;
      long long temp2 = arr[i] + add / c;
      add += min((temp1 - temp2) / 5 * b, (temp1 - temp2) * c);
      ans[k - 1][j] += add;
      update(j, i, i, add);
    }
    tot = min(tot, ans[k - 1][j]);
  }
  for (int i = k; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      long long add = (j - arr[i] % 5 + 5) % 5 * c;
      tu2 q1 = query(j, i);
      ans[i][j] = ans[i - 1][j] - q1.first + add;
      update(j, q1.second, q1.second, -(1LL << 60));
      long long temp1 = arr[i] + add / c;
      long long temp2 = arr[i - 1] + (j - arr[i - 1] % 5 + 5) % 5;
      long long addAll = min((temp1 - temp2) / 5 * b, (temp1 - temp2) * c);
      ans[i][j] += addAll * (k - 1);
      update(j, i, i, add);
      update(j, 0, i - 1, addAll);
      tot = min(tot, ans[i][j]);
    }
  }
  cout << tot << endl;
  return 0;
}
