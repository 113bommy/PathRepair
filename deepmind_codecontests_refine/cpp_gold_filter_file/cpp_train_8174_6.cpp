#include <bits/stdc++.h>
using namespace std;
int n, a[100050], b[100050];
long long sum[100050 << 1];
bool vst1[100050], vst2[100050];
int q[100050 << 1];
void sol(bool vst[]) {
  for (int i = 0; i < n; i++) {
    if (i == 0)
      sum[i] = a[i] - b[i];
    else
      sum[i] = sum[i - 1] + a[i] - b[i];
    sum[i + n] = sum[i];
  }
  int pre = 0, j = 0, top = 0, buttom = 0;
  for (int i = 0; i < n; i++) {
    while (j <= i + n - 1) {
      while (top > buttom && sum[q[top - 1]] >= sum[j]) top--;
      q[top++] = j++;
    }
    if (top > buttom && q[buttom] < i) buttom++;
    if (sum[q[buttom]] >= pre) vst[i] = true;
    pre = sum[i];
  }
}
int main() {
  while (scanf("%d", &n) == 1) {
    memset(vst1, 0, sizeof(vst1));
    memset(vst2, 0, sizeof(vst2));
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    sol(vst1);
    for (int i = 0; i < n - i - 1; i++) swap(a[i], a[n - i - 1]);
    for (int i = 0; i < n - i - 2; i++) swap(b[i], b[n - i - 2]);
    sol(vst2);
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (vst1[i] || vst2[n - i - 1]) ans++;
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
      if (vst1[i] || vst2[n - i - 1]) {
        printf("%d", i + 1);
        ans--;
        if (ans == 0)
          printf("\n");
        else
          printf(" ");
      }
  }
  return 0;
}
