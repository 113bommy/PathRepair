#include <bits/stdc++.h>
using namespace std;
vector<long long> v[100010], odv, evv;
long long ar[100010];
long long evxo, odxo;
long long mxd;
map<long long, long long> odd, even;
void dfs(long long node, long long depth) {
  mxd = max(depth, mxd);
  if (depth % 2 == 0) {
    even[ar[node]]++;
    evxo ^= ar[node];
    evv.push_back(ar[node]);
  } else {
    odd[ar[node]]++;
    odxo ^= ar[node];
    odv.push_back(ar[node]);
  }
  for (auto x : v[node]) dfs(x, depth + 1);
}
long long sum(long long n) {
  long long x = 0;
  if (n % 2 == 0)
    x += (n / 2) * (n - 1);
  else
    x += ((n - 1) / 2) * n;
  return x;
}
int main() {
  long long n, a;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> ar[i];
  for (long long i = 2; i <= n; i++) {
    cin >> a;
    v[a].push_back(i);
  }
  dfs(1, 1);
  long long ans = 0;
  if (mxd % 2 == 0) {
    for (long long i = 0; i < evv.size(); i++) {
      long long x = evxo ^ evv[i];
      ans += odd[x];
    }
    if (!evxo) ans += sum(evv.size()) + sum(odv.size());
    cout << ans << endl;
    return 0;
  }
  for (long long i = 0; i < odv.size(); i++) {
    long long x = odxo ^ odv[i];
    ans += even[x];
  }
  if (!odxo) ans += sum(evv.size()) + sum(odv.size());
  cout << ans << endl;
}
