#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18;
const long long mod = 1e9 + 7;
const double Pi = acos(-1);
long long n, sum;
long long a[100009], dp[100009];
pair<long long, long long> tree[400009];
void upd(int node, int l, int r, int id, int val) {
  if (l == r) {
    tree[node] = {val, id};
    return;
  }
  if (id <= (l + r) / 2)
    upd(node * 2, l, (l + r) / 2, id, val);
  else
    upd(node * 2 + 1, (l + r) / 2 + 1, r, id, val);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
pair<long long, long long> query(int node, int l, int r, int s, int e) {
  if (s > r || e < l) return {-1, -1};
  if (s <= l && e >= r) return tree[node];
  return max(query(node * 2, l, (l + r) / 2, s, e),
             query(node * 2 + 1, (l + r) / 2 + 1, r, s, e));
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i], a[i]--;
    upd(1, 0, n - 1, i, a[i]);
  }
  upd(1, 0, n - 1, n - 1, n - 1);
  for (int i = n - 2; i >= 0; i--) {
    long long j = query(1, 0, n - 1, i + 1, a[i]).second;
    dp[i] = dp[j] + j - a[i] + n - i - 1ll;
    sum += dp[i];
  }
  cout << sum << endl;
}
