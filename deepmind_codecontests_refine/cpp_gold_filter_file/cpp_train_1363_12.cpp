#include <bits/stdc++.h>
using namespace std;
int arr[5000 + 5];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  long double res = 0;
  for (int i = k; i <= n; i++) {
    long long sum = 0, localMax = 0;
    for (int j = 1; j <= n; j++) {
      sum += arr[j];
      sum -= arr[max(0, j - i)];
      if (j - i >= 0) localMax = max(localMax, sum);
    }
    res = max(res, (long double)localMax / (long double)i);
  }
  printf("%.10lf\n", (double)res);
  return 0;
}
