#include <bits/stdc++.h>
using namespace std;
void work() {
  int n;
  scanf("%d", &n);
  long long s = 0, x = 0;
  for (int i = 1; i <= n; i++) {
    int cur;
    scanf("%d", &cur);
    s += cur;
    x ^= cur;
  }
  long long d = s - 2 * x;
  vector<long long> ans;
  if (d != 0) {
    if (s % 2 == 1) {
      ans.push_back((1LL << 50) + 1);
    } else {
      ans.push_back((1LL << 50));
    }
    s += ans.back();
    x ^= ans.back();
    d = s - 2 * x;
    d = -d;
    ans.push_back(d / 2);
    ans.push_back(d / 2);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%lld ", ans[i]);
  }
  printf("\n");
}
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    work();
  }
  return 0;
}
