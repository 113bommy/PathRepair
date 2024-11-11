#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans += v[i];
  }
  for (int i = k; i < n; i++) {
    ans += x;
  }
  printf("%d\n", ans);
  return 0;
}
