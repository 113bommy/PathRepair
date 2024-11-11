#include <bits/stdc++.h>
using namespace std;
long long n, v, k, a[100005], b[100005], x, ans;
priority_queue<long long, vector<long long>, greater<long long> > q;
void solve() {
  cin >> n >> k;
  for (__typeof((n + 1)) i = (1); i < (n + 1); i++) cin >> a[i];
  cin >> v;
  for (__typeof((n + 1)) i = (1); i < (n + 1); i++) {
    cin >> b[i];
    q.push(b[i]);
    if (a[i] > k && q.size()) {
      k += v;
      ans += q.top();
      q.pop();
    }
    if (a[i] > k) {
      cout << -1 << "\n";
      return;
    };
  }
  {
    cout << ans << "\n";
    return;
  };
}
void prep() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  prep();
  cout << fixed << setprecision(12);
  while (t--) solve();
  return 0;
}
