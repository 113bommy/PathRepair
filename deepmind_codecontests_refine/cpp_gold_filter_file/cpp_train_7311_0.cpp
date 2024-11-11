#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
const int N = 2e5 + 10;
ll a[N], pre[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  set<ll> cur{0};
  ll ans = 0;
  for (int l = 1, r = 0; l <= n; l++) {
    if (r < l - 1) {
      r = l - 1;
      cur = set<ll>{pre[l - 1]};
    }
    while (r + 1 <= n && cur.find(pre[r + 1]) == cur.end()) {
      r++;
      cur.insert(pre[r]);
    }
    ans += r - l + 1;
    cur.erase(pre[l - 1]);
  }
  cout << ans << endl;
  return 0;
}
