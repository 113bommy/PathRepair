#include <bits/stdc++.h>
using namespace std;
int n;
int a[108];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int ans1 = 0x3f3f3f3f;
  int ans2 = -1;
  for (int i = 0; i <= 101; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] < i) cnt += i - a[j] - 1;
      if (a[j] > i) cnt += a[j] - i - 1;
    }
    if (cnt < ans1) {
      ans1 = cnt;
      ans2 = i;
    }
  }
  cout << ans2 << ' ' << ans1 << endl;
  return 0;
}
