#include <bits/stdc++.h>
using namespace std;
long long arr[101];
int main() {
  long long p, k;
  scanf("%lld %lld", &p, &k);
  if (p < k) {
    printf("%lld\n%lld\n", 1, p);
    return 0;
  }
  long long now = 1, cnt = 0;
  while (p / now >= k) {
    now *= k;
    cnt++;
  }
  long long x = p;
  while (x > 0) {
    if (x >= now) {
      arr[cnt] = x / now;
      x -= arr[cnt] * now;
      cnt--;
      now /= k;
    } else {
      cnt--;
      now /= k;
    }
  }
  for (int i = 1; i + 2 < 100; i += 2) {
    while (arr[i] >= k) {
      arr[i] -= k;
      arr[i + 1]++;
    }
    while (arr[i + 1] >= k) {
      arr[i + 1] -= k;
      arr[i + 2]++;
    }
    if (arr[i] > 0) {
      arr[i] = k - arr[i];
      arr[i + 1]++;
    }
    while (arr[i + 1] >= k) {
      arr[i + 1] -= k;
      arr[i + 2]++;
    }
  }
  int idx = 0;
  for (idx = 99; idx >= 0; idx--) {
    if (arr[idx] != 0) break;
  }
  printf("%d\n", idx + 1);
  for (int i = 0; i <= idx; i++) printf("%lld ", arr[i]);
  return 0;
}
