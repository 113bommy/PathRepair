#include <bits/stdc++.h>
using namespace std;
long long lim = 1500000LL * 1500000LL;
int main() {
  long long n;
  scanf("%lld", &n);
  pair<long long, pair<long long, long long> > arr[n];
  for (long long i = 0; i < n; i++) {
    scanf("%lld%lld", &(arr[i].first), &(arr[i].second.first));
    arr[i].second.second = i;
  }
  int res[n];
  while (1) {
    long long c1 = 0, c2 = 0;
    random_shuffle(arr, arr + n);
    for (long long i = 0; i < n; i++) {
      if ((abs(c1 - arr[i].first) + abs(c2 - arr[i].second.first)) <
          (abs(c1 + arr[i].first) + abs(c2 + arr[i].second.first))) {
        res[arr[i].second.second] = -1;
        c1 -= arr[i].first;
        c2 -= arr[i].second.first;
      } else {
        res[arr[i].second.second] = 1;
        c1 += arr[i].first;
        c2 += arr[i].second.first;
      }
    }
    if ((c1 * c1 + c2 * c2) <= lim) break;
  }
  for (long long i = 0; i < n; i++) {
    printf("%d  ", res[i]);
  }
  return 0;
}
