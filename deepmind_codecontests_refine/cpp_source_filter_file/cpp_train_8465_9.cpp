#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int SEED = 2;
long long int p[N];
long long int h[N];
std::vector<pair<int, int> > v;
map<long long int, long long int> mp;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * SEED;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
    h[x] += p[y];
    h[y] += p[x];
  }
  for (int i = 1; i <= n; i++) {
    mp[h[i]]++;
  }
  long long int ans = 0;
  for (auto i : mp) {
    ans += (i.second - 1) * i.second / 2;
  }
  for (auto i : v) {
    if (h[i.first] + p[i.first] == h[i.second] + p[i.second]) ans++;
  }
  cout << ans;
  return 0;
}
