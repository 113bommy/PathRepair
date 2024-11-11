#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
const double EPS = 1e-8;
const int MOD = 1000000007;
int n, m;
vector<pair<int, int> > g[1000];
int main() {
  scanf("%d%d", &n, &m);
  vector<int> d(n);
  for (int i = 0; i < (int)(n); i++) scanf("%d", &d[i]);
  long long int ans = 0;
  for (int i = 0; i < (int)(m); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ans += min(d[x - 1], d[y - 1]);
  }
  cout << ans << endl;
  return 0;
}
