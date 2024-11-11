#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n;
int times[N], cnt[N], times2[N];

int get(int x) {
  return times[x] + (times2[x - 1]) / x;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ++cnt[x];
  }
  for (int i = 0; i <= n; ++i) {
    if (cnt[i] > 0) {
      ++times[cnt[i]];
      times2[cnt[i]] += cnt[i];
    }
  }
  for (int i = n; i >= 0; --i)
    times[i] += times[i + 1];
  for (int i = 1; i <= n; ++i)
    times2[i] += times2[i - 1];
  for (int k = 1; k <= n; ++k) {
    int low = 0, high = n + 1;
    while (low + 1 < high) {
      int mid = (low + high) / 2;
      if (get(mid) >= k)
        low = mid;
      else
        high = mid;
    }
    printf("%d\n", low);
  }
  return 0;
}