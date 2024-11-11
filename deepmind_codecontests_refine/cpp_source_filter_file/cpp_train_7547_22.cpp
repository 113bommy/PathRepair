#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int arr[N];
const int ST_N = 200000;
int Bin[20], Log[ST_N];
int mn[20][ST_N];
void ST(int n) {
  Bin[0] = 1;
  for (int i = 1; i < 20; i++) Bin[i] = Bin[i - 1] << 1;
  for (int i = 1; i <= n; i++) mn[0][i] = arr[i];
  int k = int(log2(n));
  for (int i = 1; i <= k; i++)
    for (int j = 1; j + Bin[i] - 1 <= n; j++)
      mn[i][j] = max(mn[i - 1][j], mn[i - 1][j + Bin[i - 1]]);
}
int right_max[N], left_max[N];
void init_LR(int n) {
  int k = int(log2(n));
  int temp;
  for (int i = 1; i < n - 1; i++) {
    temp = i + 1;
    for (int j = k; j >= 0; j--)
      if (temp + (1 << j) < n && mn[j][temp] <= arr[i])
        right_max[i] += 1 << j, temp += 1 << j;
  }
  for (int i = 2; i < n; i++) {
    temp = i - 1;
    for (int j = k; j >= 0; j--)
      if (temp - (1 << j) + 1 >= 1 && mn[j][temp - (1 << j) + 1] < arr[i])
        left_max[i] += 1 << j, temp -= 1 << j;
  }
}
int seq[N];
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &seq[i]);
  for (int i = 1; i < n; i++) arr[i] = abs(seq[i + 1] - seq[i]);
  ST(n);
  init_LR(n);
  long long ans = 0;
  int l, r;
  while (q--) {
    scanf("%d %d", &l, &r);
    ans = 0;
    for (int i = l; i < r; i++)
      ans += 1LL * (min(left_max[i], i - l) + 1) *
             (min(right_max[i], r - i - 1) + 1) * arr[i];
    printf("%lld\n", ans);
  }
  return 0;
}
