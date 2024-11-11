#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 1e5 + 5, MM = 1e6 + 5, MOD = 1e9 + 7;
int N;
ll t[MM], last[MN];
void upd(int i, ll v) {
  for (; i < MM; i += i & -i) t[i] = (t[i] + v + MOD) % MOD;
}
ll get(int i) {
  ll r = 0;
  for (; i; i -= i & -i) r = (r + t[i]) % MOD;
  return r;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    ll val = get(a) * a + a;
    upd(a, -last[a]);
    upd(a, val);
    last[a] = val;
  }
  cout << get(1e6) << '\n';
  return 0;
}
