#include <bits/stdc++.h>
using namespace std;
int n, k, M, t[45], sum, ans;
bool B[45][45];
int main() {
  scanf("%d%d%d", &n, &k, &M);
  for (int i = 0; i < k; i++) scanf("%d", &t[i]);
  sort(t, t + k);
  for (int i = 0; i < k; i++) sum += t[i];
  int i = 0;
  while ((M - i * sum >= 0) && (i <= n)) {
    int cnt = (n + 1) * i;
    int summ = sum * i;
    for (int p = 0; p < k; p++)
      for (int q = 0; q < n - i; q++)
        if (summ + t[p] <= M) {
          cnt++;
          summ += t[p];
        }
    ans = max(ans, cnt);
    i++;
  }
  printf("%d\n", ans);
  return 0;
}
