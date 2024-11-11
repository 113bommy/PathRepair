#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int P[200001];
ll sum[200001];
ll fen[200001];
int ans[200001];
void build() {
  for (int i = 1; i <= 200000; i++) {
    sum[i] = sum[i - 1] + ll(i - 1);
    fen[i] = sum[i] - sum[i - (i & -i)];
  }
}
ll query(int l, int r) {
  if (l != 1LL) return query(1, r) - query(1, l - 1);
  ll ans = 0LL;
  while (r > 0) {
    ans += fen[r];
    r -= r & -r;
  }
  return ans;
}
void update(int i) {
  ll taking = i;
  i++;
  while (i <= 200000) {
    fen[i] -= taking;
    i += (i & -i);
  }
}
int find(ll s) {
  ll cur = 0LL;
  int ind = 0;
  for (int b = 17; b >= 0; b--) {
    if (ind + (1 << b) <= 200000 && cur + fen[ind + (1 << b)] <= s) {
      cur += fen[ind + (1 << b)];
      ind += (1 << b);
    }
  }
  return ind;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> P[i];
  build();
  for (int i = n; i >= 1; i--) {
    ans[i] = find(P[i]);
    update(ans[i]);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
