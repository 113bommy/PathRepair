#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> v[3010];
vector<long long> tmp;
long long ans = 9999999999999;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x;
    long long y;
    scanf("%d%lld", &x, &y);
    v[x].push_back(y);
  }
  for (int i = 1; i <= m; i++) sort(v[i].begin(), v[i].end());
  for (int k = 1; k <= n; k++) {
    long long sum = 0;
    int vote = v[1].size();
    tmp.clear();
    for (int j = 2; j <= m; j++) {
      for (int l = 0; l < v[j].size(); l++) {
        if (l < v[j].size() - k + 1) {
          vote++;
          sum += v[j][l];
        } else {
          tmp.push_back(v[j][l]);
        }
      }
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < tmp.size(); i++) {
      if (vote == k) break;
      vote++;
      sum += tmp[i];
    }
    if (vote < k) continue;
    ans = min(ans, sum);
  }
  printf("%lld\n", ans);
  return 0;
}
