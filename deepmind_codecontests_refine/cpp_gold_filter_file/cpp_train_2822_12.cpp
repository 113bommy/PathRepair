#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int bit[maxn + 11];
int n, k;
vector<int> v, x;
struct node {
  int x, r, q;
} rob[maxn + 11], tmp[maxn + 11];
int lowbit(int x) { return x & (-x); }
void update(int i, int val) {
  for (; i <= x.size(); i += lowbit(i)) bit[i] += val;
}
int query(int i) {
  int ans = 0;
  for (; i; i -= lowbit(i)) ans += bit[i];
  return ans;
}
int query(int l, int r) { return query(r) - query(l - 1); }
long long cdq(int l, int r) {
  if (l >= r) return 0;
  int mid = (l + r) >> 1;
  long long ans = cdq(l, mid) + cdq(mid + 1, r);
  int L = l, R = l;
  for (int j = mid + 1; j <= r; j++) {
    while (R <= mid && rob[R].q <= rob[j].q + k)
      update(lower_bound((x).begin(), (x).end(), rob[R].x) - x.begin() + 1, 1),
          R++;
    while (L <= mid && rob[L].q < rob[j].q - k)
      update(lower_bound((x).begin(), (x).end(), rob[L].x) - x.begin() + 1, -1),
          L++;
    int lp = lower_bound((x).begin(), (x).end(), rob[j].x - rob[j].r) -
             x.begin() + 1;
    int rp =
        upper_bound((x).begin(), (x).end(), rob[j].x + rob[j].r) - x.begin();
    if (lp <= rp) ans += query(lp, rp);
  }
  for (int i = L; i < R; i++)
    update(lower_bound((x).begin(), (x).end(), rob[i].x) - x.begin() + 1, -1);
  int i = l, j = mid + 1, pos = l;
  for (; i <= mid && j <= r;) {
    if (rob[i].q <= rob[j].q)
      tmp[pos++] = rob[i++];
    else
      tmp[pos++] = rob[j++];
  }
  if (i <= mid) {
    for (; i <= mid; i++) tmp[pos++] = rob[i];
  }
  if (j <= r) {
    for (; j <= r; j++) tmp[pos++] = rob[j];
  }
  for (i = l; i <= r; i++) rob[i] = tmp[i];
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> rob[i].x >> rob[i].r >> rob[i].q;
    v.emplace_back(rob[i].q);
    x.emplace_back(rob[i].x);
  }
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
  sort((x).begin(), (x).end());
  x.erase(unique((x).begin(), (x).end()), x.end());
  sort(rob + 1, rob + 1 + n, [&](node x, node y) { return x.r > y.r; });
  cout << cdq(1, n) << endl;
}
