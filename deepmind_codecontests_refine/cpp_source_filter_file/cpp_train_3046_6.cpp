#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
vector<int> calcZFunction(string &s) {
  int n = s.size();
  vector<int> ans(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i <= r) {
      ans[i] = min(ans[i - l], r - i + 1);
    }
    while (i + ans[i] < n && s[ans[i]] == s[i + ans[i]]) ans[i]++;
    if (i + ans[i] - 1 > r) {
      l = i;
      r = i + ans[i] - 1;
    }
  }
  return ans;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int mx = 0;
  int ind = 0;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= k;
    if (a[i]) {
      cnt[a[i]]++;
      if (mx < cnt[a[i]]) {
        mx = cnt[a[i]];
        ind = a[i];
      } else if (mx == cnt[a[i]] && a[i] < ind) {
        ind = a[i];
      }
    }
  }
  if (mx) {
    cout << 1L * (mx - 1) * k + (k - ind + 1) << endl;
  } else
    cout << 0 << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
