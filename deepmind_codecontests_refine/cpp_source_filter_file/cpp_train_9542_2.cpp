#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long a[100005];
long long cost[100005];
map<string, int> gp;
string str[100005];
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = 0; i < n; i++) {
    int t;
    int tmp;
    scanf("%d", &t);
    cost[i] = inf;
    for (int j = 0; j < t; j++) {
      scanf("%d", &tmp);
      tmp--;
      gp[str[tmp]] = i;
      cost[i] = min(cost[i], a[tmp]);
    }
  }
  long long ans = 0;
  string s;
  for (int i = 0; i < m; i++) {
    cin >> s;
    ans += cost[gp[s]];
  }
  printf("%lld\n", ans);
  return 0;
}
