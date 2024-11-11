#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 100;
const int INF = (int)1e9 + 100;
int n, k, a[maxn];
vector<int> vec[maxn];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (1); i <= (n); ++i) {
    int x, t = 0;
    scanf("%d", &x);
    while (x) {
      vec[x].push_back(t);
      x /= 2;
      t++;
    }
  }
  int ans = INF;
  for (int i = (1); i <= (n); ++i)
    if (vec[i].size() >= k) {
      sort(vec[i].begin(), vec[i].end());
      ans = min(ans, accumulate(vec[i].begin(), vec[i].begin() + k, 0));
    }
  printf("%d\n", ans);
}
