#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 9;
const int inf = 1e9 + 9;
const int N = 1e5 + 9;
pair<int, int> arr[N];
int n, k, size;
int bs(int temp, int i) {
  int bas = 0;
  int son = n;
  int res = 0;
  while (bas + 1 < son) {
    int orta = bas + son >> 1;
    if (arr[orta].first > temp * k)
      son = orta;
    else {
      if (arr[orta].first == (long long)temp * k) {
        arr[orta].second = 1;
        int prev = 0;
        for (long long j = i; j < orta; j++) {
          if (arr[j].second >= 1)
            prev++;
          else
            arr[j].second = inf;
        }
        return orta - i - prev;
      }
      bas = orta;
    }
  }
  return arr[i].second == 0;
}
int main() {
  scanf("%d %d", &n, &k);
  if (k == 1) {
    printf("%d", n), puts("");
    return 0;
  }
  for (int i = 0; i < n; i++) scanf("%d", &arr[i].first);
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    if (arr[i].second == 1) continue;
    size += bs(arr[i].first, i);
  }
  printf("%d", size), puts("");
  return 0;
}
