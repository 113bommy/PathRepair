#include <bits/stdc++.h>
using namespace std;
long long cnt[5001][5001];
int main() {
  long long n, t, arr[5001], ans[5001], max, dominant;
  for (int i = 0; i < 5001; i++) {
    for (int j = 0; j < 5001; j++) {
      cnt[i][j] = 0;
    }
    arr[i] = 0;
  }
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &arr[i]);
  }
  for (int i = 1; i <= n; i++) {
    max = -1;
    dominant = -1;
    for (int j = i; j <= n; j++) {
      cnt[i][arr[j]]++;
      if (max < cnt[i][arr[j]]) {
        max = cnt[i][arr[j]];
        ans[arr[j]]++;
        dominant = arr[j];
      } else if (max == cnt[i][arr[j]]) {
        if (arr[j] < dominant) dominant = arr[j];
        ans[dominant]++;
      } else {
        ans[dominant]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld ", ans[i]);
  }
  return 0;
}
