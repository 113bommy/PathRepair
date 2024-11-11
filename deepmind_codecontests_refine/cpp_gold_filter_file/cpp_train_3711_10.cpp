#include <bits/stdc++.h>
using namespace std;
const int MX = 100005;
const int LG = log2(MX) + 2;
const int mod = 1000000007;
const int inf = 1000000069;
const long long infll = 1000000000000000069ll;
int n;
long long ans[MX];
vector<long long> bt[65];
long long msb(long long x) { return (long long)log2(x); }
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    bt[msb(x)].push_back(x);
  }
  long long nw = 0ll;
  for (int i = 1; i <= n; i++) {
    bool fla = 0;
    for (int j = 0; j < 60; j++) {
      if (((1ll << j) & nw) || bt[j].empty()) continue;
      nw ^= bt[j].back();
      ans[i] = bt[j].back();
      bt[j].pop_back();
      fla = 1;
      break;
    }
    if (!fla) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
