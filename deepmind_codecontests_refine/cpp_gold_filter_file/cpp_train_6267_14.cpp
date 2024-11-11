#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, m = 0;
long long solve(int x) {
  int mid = x >> 1;
  long long ans = 0;
  for (int i = 0; i < v.size(); i += x) {
    for (int j = 0; j < x; ++j) {
      ans += abs(v[i + j] - v[i + mid]);
    }
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    if (x) {
      m++;
      v.push_back(i);
    }
  }
  if (m < 2) {
    printf("-1\n");
    return 0;
  }
  long long ans = 2e18;
  for (int i = 2; i <= m; ++i) {
    if (m % i == 0) {
      ans = min(ans, solve(i));
    }
  }
  printf("%lld\n", ans);
  return 0;
}
