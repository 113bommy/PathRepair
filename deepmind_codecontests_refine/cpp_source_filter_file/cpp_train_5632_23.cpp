#include <bits/stdc++.h>
using namespace std;
int N, K;
int arr[105];
int ans = 0;
int sum = 0;
int hashCnt[105];
int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < K; i++) {
    scanf("%d", &arr[i]);
    hashCnt[arr[i]]++;
  }
  for (int i = 1; i <= N; i++) {
    sum = 0;
    for (int j = 0; j < 105; j++) {
      sum += hashCnt[j] / i;
    }
    if (sum >= N) {
      ans = max(ans, i);
    }
  }
  printf("%d\n", ans);
  return 0;
}
