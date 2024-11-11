#include <bits/stdc++.h>
using namespace std;
const long long MAX = 5e5 + 10;
long long inf = (long long)3e18;
long long mod = (long long)998244353;
long long mb = 1;
long long n, inds[MAX], ar[MAX];
vector<pair<long long, long long>> out;
long long ans = 0;
void push(long long ind) {
  for (int i = ind - 1; i > 0; i--) {
    if (i < inds[ar[i]]) {
      out.push_back({ind, i});
      ans += ind - i;
      swap(ar[ind], ar[i]);
      ind = i;
    }
    if (ind == inds[ar[ind]]) break;
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  for (int i = 1; i <= n; i++) {
    long long a;
    cin >> a;
    inds[a] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j > inds[ar[j]]) {
        push(j);
        break;
      }
    }
  }
  cout << ans << "\n" << out.size() << "\n";
  for (int i = 0; i < out.size(); i++)
    cout << out[i].first << " " << out[i].second << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  long long q;
  q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
