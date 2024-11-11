#include <bits/stdc++.h>
using namespace std;
long long int em(long long int x, long long int Mod, long long int n) {
  if (n == 0)
    return 1ll;
  else if (n % 2 == 0)
    return em((x % Mod * x % Mod) % Mod, Mod, n / 2) % Mod;
  else
    return (x % Mod * em((x % Mod * x % Mod) % Mod, Mod, (n - 1) / 2)) % Mod;
}
vector<long long int> msg;
long long int t[4 * 300009][2];
void build(long long int node, long long int l, long long int r,
           long long int ty) {
  if (l > r) return;
  if (l == r) {
    if (!ty)
      t[node][ty] = msg[l];
    else
      t[node][ty] = l;
    return;
  }
  long long int mid = (l + r) / 2;
  build(2 * node, l, mid, ty);
  build(2 * node + 1, mid + 1, r, ty);
}
void update(long long int node, long long int l, long long int r,
            long long int st, long long int en, long long int val,
            long long int ty) {
  if (l > r || st > r || en < l) return;
  if (l >= st && r <= en) {
    t[node][ty] += val;
    return;
  }
  long long int mid = (l + r) / 2;
  update(2 * node, l, mid, st, en, val, ty);
  update(2 * node + 1, mid + 1, r, st, en, val, ty);
}
long long int query(long long int node, long long int l, long long int r,
                    long long int pos, long long int ty) {
  if (l == r) return t[node][ty];
  long long int mid = (l + r) / 2;
  if (pos <= mid)
    return t[node][ty] + query(2 * node, l, mid, pos, ty);
  else
    return t[node][ty] + query(2 * node + 1, mid + 1, r, pos, ty);
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, i, j, k, l;
  cin >> n >> m;
  msg.assign(m + 1, 0);
  long long int last[n + 1];
  pair<long long int, long long int> ans[n + 1];
  for (long long int i = (long long int)1; i < (long long int)n + 1; i++)
    ans[i] = {i, i};
  memset(last, -1, sizeof(last));
  for (long long int i = (long long int)0; i < (long long int)m; i++)
    cin >> msg[i];
  build(1, 0, m - 1, 0);
  build(1, 1, n, 1);
  for (long long int i = (long long int)0; i < (long long int)m; i++) {
    ans[msg[i]].first = 1;
    if (last[msg[i]] == -1) {
      long long int ind = query(1, 1, n, msg[i], 1);
      ans[msg[i]].second = max(ans[msg[i]].second, ind);
      update(1, 1, n, 1, msg[i] - 1, 1, 1);
      update(1, 0, m - 1, 0, i - 1, 1, 0);
      update(1, 0, m - 1, i, i, -msg[i] + 1, 0);
      last[msg[i]] = i;
    } else {
      long long int ind = query(1, 0, m - 1, last[msg[i]], 0);
      ans[msg[i]].second = max(ans[msg[i]].second, ind);
      update(1, 0, m - 1, last[msg[i]] + 1, i - 1, 1, 0);
      update(1, 0, m - 1, i, i, -ind + 1, 0);
      last[msg[i]] = i;
    }
  }
  for (long long int i = (long long int)1; i < (long long int)n + 1; i++) {
    cout << ans[i].first << " ";
    if (last[i] == -1)
      cout << max(ans[i].second, query(1, 1, n, i, 1)) << "\n";
    else
      cout << max(ans[i].second, query(1, 0, m - 1, last[i], 0)) << "\n";
  }
}
