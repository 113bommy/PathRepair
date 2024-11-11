#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
int n;
pair<long long, int> t[N];
long long tree[4 * N], dp[N], v[N];
int rnk[N];
void update(int idx, long long val, int st, int en, int root) {
  if (idx < st || idx > en) return;
  if (st == en) {
    tree[root] = max(tree[root], val);
    return;
  }
  int mid = (st + en) >> 1;
  update(idx, val, st, mid, root * 2);
  update(idx, val, mid + 1, en, root * 2 + 1);
  tree[root] = max(tree[root * 2], tree[root * 2 + 1]);
}
long long query(int L, int R, int st, int en, int root) {
  if (L > en || R < st) return 0;
  if (st >= L && en <= R) return tree[root];
  int mid = (st + en) >> 1;
  return max(query(L, R, st, mid, root * 2),
             query(L, R, mid + 1, en, root * 2 + 1));
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int h, r;
    scanf("%d %d", &r, &h);
    v[i] = 1LL * r * r * h;
    t[i] = make_pair(v[i], i);
  }
  sort(t, t + n);
  rnk[t[0].second] = 0;
  for (int i = 1; i < n; i++)
    rnk[t[i].second] = rnk[t[i - 1].second] + (t[i].first > t[i - 1].first);
  for (int i = 0; i < n; i++) {
    dp[i] = v[i];
    long long best = query(0, rnk[i] - 1, 0, n - 1, 1);
    dp[i] += best;
    update(rnk[i], dp[i], 0, n - 1, 1);
  }
  long long ret = 0;
  for (int i = 0; i < n; i++) ret = max(ret, dp[i]);
  cout << fixed << setprecision(12) << acos(-1) * ret << '\n';
}
