#include <bits/stdc++.h>
using namespace std;
int n, a[100005], b;
vector<int> v[100005];
int x[300];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cin >> b;
    v[a[i]].push_back(b);
    sum += b;
  }
  int res = 2000000009;
  for (int i = 1; i <= 100000; i++) {
    int ns = (int)v[i].size() - 1;
    int rr = 0;
    for (int j = 200; j >= 1; j--) {
      rr += min(x[j], ns) * j;
      ns -= min(x[j], ns);
    }
    for (auto k : v[i]) {
      rr += k;
      x[k]++;
    }
    res = min(res, sum - rr);
  }
  cout << res;
  return 0;
}
