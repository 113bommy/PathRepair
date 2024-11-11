#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int cur = 0, ans = 0, qian = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cur++;
    } else {
      if (v[i] == v[i - 1]) {
        cur++;
      } else {
        ans = max(ans, min(qian, cur));
        qian = cur;
        cur = 1;
      }
    }
  }
  ans = max(ans, min(qian, cur));
  printf("%d\n", ans << 1);
  return 0;
}
