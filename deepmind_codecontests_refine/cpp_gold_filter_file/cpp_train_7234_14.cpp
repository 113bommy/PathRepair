#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> h(n), res(n);
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d", &h[i]);
  }
  int bad = 0;
  int ans = 0;
  for (int i = 0; i < (int)(n); i++) {
    bad = min(bad, h[i] - i - 1);
    res[i] = i + 1 + bad;
  }
  bad = n + 1;
  for (int i = (int)(n)-1; i >= 0; i--) {
    bad = min(bad, h[i] + i + 1);
    res[i] = min(res[i], bad - i - 1);
    ans = max(ans, res[i]);
  }
  printf("%d\n", ans);
}
