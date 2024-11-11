#include <bits/stdc++.h>
#pragma warning(disable : 4786)
#pragma comment(linker, "/STACK:26777216")
using namespace std;
const long long MOD = 100000007;
const long long LINF = 1000000097999999903LL;
long long boundz = 10000000001;
const int INF = (1 << 29);
int arr[100005], brr[2005];
int leftPos[100005], rightPos[100005];
int dp[100005];
int N, M;
void reset() {
  memset(arr, 0, sizeof(arr));
  memset(brr, 0, sizeof(brr));
}
int main() {
  scanf("%d %d", &N, &M);
  reset();
  leftPos[0] = 1;
  rightPos[N + 1] = N;
  for (int i = (1); i <= (N); i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = (1); i <= (M); i++) {
    scanf("%d", &brr[i]);
  }
  sort(arr + 1, arr + N + 1);
  sort(brr + 1, brr + M + 1);
  for (int i = (1); i <= (N); i++) {
    if (arr[i] == arr[i - 1] + 1) {
      leftPos[i] = leftPos[i - 1];
    } else {
      leftPos[i] = i;
    }
  }
  for (int i = (N); i >= (1); i--) {
    if (arr[i] == arr[i + 1] + 1) {
      rightPos[i] = rightPos[i + 1];
    } else {
      rightPos[i] = i;
    }
  }
  for (int i = (1); i <= (N); i++) {
    dp[i] = -INF;
  }
  dp[0] = 0;
  int ret = 0;
  int j = 0;
  for (int i = (1); i <= (N); i++) {
    if (rightPos[i] != i) continue;
    while (j + 1 <= M && brr[j + 1] <= arr[i]) {
      j++;
    }
    ret = dp[leftPos[i] - 1];
    for (int k = (j); k >= (1); k--) {
      int dist = arr[i] - brr[k];
      int pos = i - dist;
      if (pos < 1) break;
      ret = max(ret, dp[leftPos[pos] - 1] + (j - k + 1));
    }
    dp[i] = max(dp[i], ret);
    for (int k = (j + 1); k <= (M); k++) {
      int dist = brr[k] - arr[i];
      int pos = i + dist;
      if (pos > N) break;
      dp[rightPos[pos]] = max(dp[rightPos[pos]], ret + k - j);
    }
    if (i + 1 <= N && dp[rightPos[i + 1]] < dp[i]) {
      dp[rightPos[i + 1]] = dp[i];
    }
  }
  printf("%d\n", dp[N]);
  return 0;
}
