#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5 + 5;
long long n, m, a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  long long sum = 0;
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  bool ok = true;
  long long cur = n;
  vector<int> ans(m);
  for (int i = m - 1; i >= 0; --i) {
    cur = max(i * 1ll, cur - a[i]);
    ans[i] = cur + 1;
    if (cur + a[i] > n) ok = false;
  }
  if (ok && ans[0] == 1) {
    for (auto x : ans) cout << x << " ";
    cout << "\n";
  } else
    cout << -1 << "\n";
}
