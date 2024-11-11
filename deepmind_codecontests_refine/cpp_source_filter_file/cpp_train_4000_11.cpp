#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[222222];
int main(int argc, char* argv[]) {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++)
    scanf("%d", &a[i].second), scanf("%d", &a[i].first);
  sort(a + 1, a + m + 1);
  reverse(a + 1, a + m + 1);
  int k = 1;
  for (int i = 1; i <= m; i++) {
    if (i <= 2) {
      k = i;
      continue;
    }
    int j;
    if (i % 2 == 0)
      j = i - 1;
    else
      j = i;
    long long cnt = 1ll * j * (j - 1) / 2 + 1;
    if (i % 2 == 0) cnt += i + i / 2 - 1;
    if (cnt <= n) k = i;
  }
  long long ans = 0;
  k = ((k) > (n) ? (n) : (k));
  for (int i = 1; i <= k; i++) ans += a[i].first;
  cout << ans << endl;
  return 0;
}
