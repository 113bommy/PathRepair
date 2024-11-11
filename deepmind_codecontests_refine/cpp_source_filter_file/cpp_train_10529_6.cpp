#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, q, i, j, l, r;
  cin >> n >> q;
  int auxi[n + 2], sum[n + 2];
  memset(auxi, 0, sizeof(auxi));
  memset(sum, 0, sizeof(sum));
  vector<pair<int, int> > v;
  for (i = 0; i < q; i++) {
    cin >> l >> r;
    v.push_back({l, r});
    auxi[r + 1] -= 1;
    auxi[l] += 1;
  }
  int net = 0;
  for (i = 0; i <= n; i++) {
    net += auxi[i];
    sum[i] += net;
  }
  int ans = 0;
  for (i = 0; i < q; i++) {
    for (j = 0; j <= n; j++) {
      auxi[i] = sum[i];
    }
    int count = 0;
    for (j = v[i].first; j <= v[i].second; j++) {
      auxi[j]--;
    }
    int prefix[n + 1];
    prefix[0] = 0;
    for (j = 1; j <= n; j++) {
      prefix[j] = prefix[j - 1] + (auxi[j] == 1);
      if (auxi[j]) count++;
    }
    for (j = i + 1; j < q; j++) {
      ans = max(ans, count - prefix[v[j].second] + prefix[v[j].first - 1]);
    }
  }
  cout << ans << "\n";
}
