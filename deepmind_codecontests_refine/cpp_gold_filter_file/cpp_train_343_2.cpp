#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  long long int k;
  cin >> n >> k;
  vector<pair<long long int, long long int>> ones, twos;
  long long int cost = 0;
  long double ans = 0;
  vector<long long int> v[1005];
  long type;
  for (long long int i = 0; i < n; i++) {
    cin >> cost >> type;
    if (type == 1)
      ones.push_back({cost, i + 1});
    else
      twos.push_back({cost, i + 1});
  }
  sort(ones.begin(), ones.end());
  sort(twos.begin(), twos.end());
  long long int p = min(k - 1, (long long int)ones.size());
  long long int flag = 0;
  long long int u = 0;
  if (p == k - 1)
    flag = 1, u = 1;
  else
    flag = p;
  while (p >= 1) {
    double y = (*(--ones.end())).first;
    v[p].push_back((*(--ones.end())).second);
    ans += double((y / 2));
    ones.pop_back();
    p -= 1;
  }
  long long int ans2 = 0;
  long long int mi = 10000000007;
  long long int l = 0;
  if (u == 1) {
    while (ones.size()) {
      l = 1;
      v[k].push_back((*(--ones.end())).second);
      ans2 += (*(--ones.end())).first;
      mi = min(mi, (*(--ones.end())).first);
      ones.pop_back();
    }
    while (twos.size()) {
      v[k].push_back((*(--twos.end())).second);
      ans2 += (*(--twos.end())).first;
      mi = min(mi, (*(--twos.end())).first);
      twos.pop_back();
    }
    ans += ans2;
    if (l == 1) {
      ans -= mi;
      double g = mi;
      ans += double((g / 2));
    }
  } else {
    long long int z = flag + 1;
    while (z <= k - 1) {
      v[z].push_back((*(--twos.end())).second);
      ans += (*(--twos.end())).first;
      twos.pop_back();
      z++;
    }
    while (twos.size()) {
      v[k].push_back((*(--twos.end())).second);
      ans += (*(--twos.end())).first;
      twos.pop_back();
    }
  }
  cout << fixed << setprecision(1) << ans << "\n";
  for (long long int i = 1; i <= k; i++) {
    cout << v[i].size() << " ";
    for (auto j : v[i]) cout << j << " ";
    cout << "\n";
  }
  return 0;
}
