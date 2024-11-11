#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> as(m);
  vector<int> bs(m);
  vector<int> cs(m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &as[i], &bs[i], &cs[i]);
    as[i]--;
    bs[i]--;
  }
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    int idx;
    scanf("%d", &idx);
    idx--;
    long long tmp = 0;
    for (int j = 0; j < m; j++) {
      if (as[j] <= idx && idx <= bs[j]) {
        tmp += idx - as[j] + cs[j];
      }
    }
    ans += tmp;
  }
  printf("%I64d\n", ans);
  return 0;
}
