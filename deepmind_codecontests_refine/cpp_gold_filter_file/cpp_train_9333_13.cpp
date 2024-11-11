#include <bits/stdc++.h>
using namespace std;
long long pow2[61];
vector<long long> ans;
int main() {
  std::ios_base::sync_with_stdio(false);
  pow2[0] = 1;
  pow2[1] = 2;
  for (int i = 2; i <= 60; i++) pow2[i] = pow2[i - 1] * 2;
  long long X, d;
  scanf("%lld %lld", &X, &d);
  while (X > 1) {
    long long k = 0;
    while (pow2[k] - 1 < X) k++;
    k--;
    long long j = 1;
    if (ans.size()) {
      j = ans.back() + d;
    }
    for (int i = 1; i <= k; i++) ans.push_back(j);
    X -= pow2[k] - 1;
  }
  if (X == 1) {
    if (ans.size())
      ans.push_back(ans.back() + d);
    else
      ans.push_back(1);
  }
  if (ans.size() > 10000)
    printf("-1\n");
  else {
    printf("%lu\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
      if (ans[i] >= 1e18) return 0 * printf("-1\n");
    for (int i = 0; i < ans.size(); i++) printf("%lld ", ans[i]);
    printf("\n");
  }
  return 0;
}
