#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g;
vector<long long> ans;
int nn, n;
bool pr[50010];
void dfs(int b, int z) {
  if (b == g.size()) {
    ans.push_back(1ll * nn * (z - 1) / 2 + z);
    return;
  }
  int c = z;
  for (int j = 0; j <= g[b].first; j++) {
    dfs(b + 1, c);
    c *= g[b].second;
  }
}
int main() {
  scanf("%d", &n);
  nn = n;
  for (int i = 2; i <= 50000; ++i) {
    if (!pr[i]) {
      for (long long j = 1ll * i * i; j <= 50000; j += i) pr[j] = 1;
      int ret = 0;
      while (n % i == 0) {
        ++ret;
        n /= i;
      }
      if (ret) g.push_back(make_pair(ret, i));
    }
  }
  if (n > 1) g.push_back(make_pair(1, n));
  dfs(0, 1);
  sort(ans.begin(), ans.end());
  for (auto i : ans) cout << i << " ";
}
