#include <bits/stdc++.h>
using namespace std;
int ara[200005];
vector<pair<int, int> > v;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &ara[i]);
  int last = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (ara[i] < 0) {
      if (last) v.push_back(make_pair(i - last, last));
      last = i;
      cnt++;
    }
  }
  if (k < cnt) {
    printf("-1");
    return 0;
  }
  sort(v.begin(), v.end());
  int ans = 2 * cnt;
  k = k - cnt;
  for (int i = 0; i < v.size(); i++) {
    pair<int, int> p = v[i];
    if (p.first - 1 <= k) {
      ans -= 2;
      k -= (p.first - 1);
    }
  }
  if (last && k >= n - last) ans--;
  printf("%d\n", ans);
}
