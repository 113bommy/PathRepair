#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> arr[1000009];
int main() {
  long long n, d;
  scanf("%lld", &n);
  scanf("%lld", &d);
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &arr[i].first);
    scanf("%lld", &arr[i].second);
  }
  sort(arr, arr + n);
  long long sum, maxx, x, y;
  sum = maxx = x = y = 0;
  for (long long i = 0; i < n; i++) {
    if (abs(arr[i].first - arr[y].first) < d)
      sum += arr[i].second;
    else {
      while (abs(arr[i].first - arr[y++].first) >= d) {
        sum -= arr[y - 1].second;
      }
      sum += arr[i].second;
      y--;
    }
    maxx = max(maxx, sum);
  }
  printf("%lld\n", maxx);
  return 0;
}
