#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int N[maxn], temp[maxn];
int main() {
  int n;
  scanf("%d", &n);
  n *= 2;
  for (int i = 0; i < n; i++) scanf("%d", &N[i]);
  sort(N, N + n);
  int ans = INF;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int cnt = 0;
      for (int k = 0; k < n; k++)
        if (k != i && k != j) temp[cnt++] = N[k];
      int tempans = 0;
      for (int k = 0; k < cnt; k += 2) tempans += temp[k + 1] - temp[k];
      ans = min(ans, tempans);
    }
  printf("%d\n", ans);
  return 0;
}
