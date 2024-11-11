#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) scanf("%d%d", &v[i].first, &v[i].second);
  long long ans = v[0].first;
  for (int i = 1; i < n; i++)
    if (v[i].first > ans)
      ans = v[i].first;
    else {
      int tmp = v[i].first;
      while (ans >= tmp) tmp += v[i].second;
      ans = tmp;
    }
  printf("%lld\n", ans);
  return 0;
}
