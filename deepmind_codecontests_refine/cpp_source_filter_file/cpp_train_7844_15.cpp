#include <bits/stdc++.h>
using namespace std;
int a[101] = {0};
set<pair<int, int> > s;
int main() {
  int n;
  scanf("%d", &n);
  if (n < 3) {
    printf("-1\n");
    return 0;
  }
  int x = n / 2, cnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > 0 && i >= x) s.insert(pair<int, int>(a[i], i));
  }
  if (!(n & 1) && a[n - 1] > 0) {
    printf("-1\n");
    return 0;
  }
  for (int i = n - 1; i > 0; i -= 2) {
    int i2 = i - 1, i3 = (i - 1) >> 1;
    while (a[i2] > 0 || a[i3] > 0) {
      cnt++;
      a[i]--;
      a[i2]--;
      a[i3]--;
    }
  }
  if (a[0] > 0) cnt += a[0];
  printf("%d\n", cnt);
  return 0;
}
