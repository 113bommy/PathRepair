#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 100;
int n, m;
int cnt[31];
int b[MAXN];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    for (int k = 0; k < 31; k++)
      if (a >> k & 1) cnt[k]++;
  }
  int ans = 0;
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  sort(b, b + m);
  for (int i = 0; i < m; i++) {
    int a = b[i];
    if (cnt[a] > 0)
      ans++, cnt[a]--;
    else {
      for (int l = a + 1; l < 31; l++) {
        if (cnt[l] > 0) {
          cnt[l]--;
          for (int s = l - 1; l >= a; l--) cnt[s]++;
          ans++;
          break;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
