#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int cnt[100010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    cnt[x]++;
    cnt[y]++;
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (!(cnt[i] & 1)) ok = false;
  }
  if (ok)
    printf("YES");
  else
    printf("NO");
  getchar();
  getchar();
  return 0;
}
