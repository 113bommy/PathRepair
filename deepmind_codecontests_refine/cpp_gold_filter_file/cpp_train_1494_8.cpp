#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
vector<int> v[N], pos[N];
int a[N];
int main(void) {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int num = v[a[i]].size();
    vector<int>::iterator iter;
    iter = lower_bound(v[a[i]].begin(), v[a[i]].end(), i - num - k);
    if (v[a[i]].size() != 0) {
      int u = iter - v[a[i]].begin();
      ans = max(ans, num - u + 1);
    }
    v[a[i]].push_back(i - num);
    pos[a[i]].push_back(i);
  }
  printf("%d\n", ans);
  return 0;
}
