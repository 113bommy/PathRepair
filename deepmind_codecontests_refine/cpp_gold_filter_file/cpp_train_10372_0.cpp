#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int vis[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> v;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    int cur = i;
    int sz = 0;
    while (!vis[cur]) {
      vis[cur] = 1;
      cur = a[cur];
      sz++;
    }
    if (sz) v.push_back(sz);
  }
  long long ans = 0;
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  if (v.size() == 1) {
    ans = v[0] * v[0];
  } else {
    ans += (v[0] + v[1]) * (v[0] + v[1]);
    for (int i = 2; i < v.size(); ++i) {
      ans += v[i] * (v[i]);
    }
  }
  cout << ans << '\n';
}
