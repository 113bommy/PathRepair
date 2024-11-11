#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n;
long long arr[N], dp[25][N];
int LOG[N];
bool vis[N];
set<long long> dui;
void rmq_init() {
  int i, j, m = LOG[n];
  for (i = 1; i <= m; i++) {
    for (j = 1; j + (1 << i) - 1 <= n; j++) {
      dp[i][j] = dp[i - 1][j] | dp[i - 1][j + (1 << (i - 1))];
    }
  }
}
int L[N], R[N];
int zhan[N], top;
long long rmq(int l, int r) {
  int m = LOG[r - l + 1];
  return (dp[m][l] | dp[m][r - (1 << m) + 1]);
}
bool check(int l, int r, long long val) { return rmq(l, r) == val; }
int main() {
  int i, j;
  scanf("%d", &n);
  long long tmp = 2;
  memset(LOG, 0, sizeof(LOG));
  for (i = 1; i <= 20 && tmp < N; i++) {
    LOG[tmp]++;
    tmp *= 2;
  }
  for (i = 1; i <= N; i++) LOG[i] += LOG[i - 1];
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &arr[i]);
    dp[0][i] = arr[i];
  }
  rmq_init();
  top = 0;
  for (i = 1; i <= n; i++) {
    while (top) {
      int now = zhan[top];
      if (arr[now] < arr[i])
        top--;
      else
        break;
    }
    if (top)
      L[i] = zhan[top];
    else
      L[i] = 0;
    zhan[++top] = i;
  }
  top = 0;
  for (i = n; i >= 1; i--) {
    while (top) {
      int now = zhan[top];
      if (arr[now] <= arr[i])
        top--;
      else
        break;
    }
    if (top)
      R[i] = zhan[top];
    else
      R[i] = n + 1;
    zhan[++top] = i;
  }
  long long ans = (n * (1LL) * (n + 1)) / 2;
  for (i = 1; i <= n; i++) {
    int LL, RR;
    int l = i, r = R[i] - 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (check(i, mid, arr[i]))
        l = mid;
      else
        r = mid;
    }
    if (check(i, r, arr[i]))
      RR = r;
    else
      RR = l;
    l = L[i] + 1, r = i;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (check(mid, i, arr[i]))
        r = mid;
      else
        l = mid;
    }
    if (check(l, i, arr[i]))
      LL = l;
    else
      LL = r;
    ans -= (RR - i + 1) * 1LL * (i - LL + 1);
  }
  printf("%I64d\n", ans);
  return 0;
}
