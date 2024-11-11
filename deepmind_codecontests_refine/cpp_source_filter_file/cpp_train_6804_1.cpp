#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return a > b; }
long long prefix_sums[100005];
int main() {
  long long n, k, arr[100005];
  scanf("%lld %lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  sort(arr, arr + n, comp);
  prefix_sums[0] = arr[0];
  for (int i = 1; i < n; i++) prefix_sums[i] = arr[i] + prefix_sums[i - 1];
  long long ans = 0, cnt = 1, j = 1, num;
  for (int i = 0; i < n; i++) {
    while (arr[i] * cnt - (prefix_sums[j] - prefix_sums[i]) <= k and j < n) {
      cnt++;
      j++;
    }
    if (ans < cnt) {
      ans = cnt;
      num = arr[i];
    }
    if (cnt > 0) cnt--;
  }
  printf("%lld %lld\n", ans, num);
  return 0;
}
