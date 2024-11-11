#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
const int MAXLOG = 20;
int Log[MAXN + 10], Min[MAXN + 10][MAXLOG + 2], n;
long long sum1[MAXN + 10], sum2[MAXN + 10], sum3[MAXN + 10], sum4[MAXN + 10],
    res[MAXN + 10];
int getMin(int l, int r) {
  int len = r - l + 1;
  return min(Min[l][Log[len]], Min[r - (1 << Log[len]) + 1][Log[len]]);
}
pair<int, int> getRange(int p) {
  int v = Min[p][0], L, R, retL = p, retR = p;
  L = 1, R = p - 1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (getMin(mid, p - 1) >= v) {
      retL = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  L = p + 1, R = n;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (getMin(p + 1, mid) > v) {
      retR = mid;
      L = mid + 1;
    } else
      R = mid - 1;
  }
  return make_pair(retL, retR);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &Min[i][0]);
  for (int i = 2; i <= n; i++) Log[i] = Log[i >> 1] + 1;
  for (int j = 1; j <= MAXLOG; j++) {
    for (int i = 1; i <= n; i++) {
      if (i + (1 << (j - 1)) > n)
        Min[i][j] = Min[i][j - 1];
      else
        Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    pair<int, int> rng = getRange(i);
    int Left_len = i - rng.first + 1;
    int Right_len = rng.second - i + 1;
    if (Left_len > Right_len) swap(Left_len, Right_len);
    int sum_len = Left_len + Right_len - 1;
    sum1[1] += Min[i][0];
    sum1[Left_len + 1] -= Min[i][0];
    sum2[Left_len + 1] += 1ll * Left_len * Min[i][0];
    sum2[sum_len - (Left_len - 1) + 1] -= 1ll * Left_len * Min[i][0];
    sum3[sum_len] -= 1ll * (n - sum_len) * Min[i][0];
    sum4[sum_len] += Min[i][0];
    sum3[sum_len - (Left_len - 1)] += 1ll * (n - sum_len) * Min[i][0];
    sum4[sum_len - (Left_len - 1)] -= Min[i][0];
  }
  long long cur = 0, cur2 = 0;
  for (int i = 1; i <= n; i++) {
    cur += sum1[i];
    res[i] += cur * i;
  }
  cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += sum2[i];
    res[i] += cur;
  }
  cur = cur2 = 0;
  for (int i = n; i >= 1; i--) {
    cur += sum3[i];
    cur2 += sum4[i];
    res[i] += (n - i + 1) * cur2 + cur;
  }
  int m, k;
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &k);
    printf("%.10f\n", 1.0 * res[k] / (n - k + 1));
  }
  return 0;
}
