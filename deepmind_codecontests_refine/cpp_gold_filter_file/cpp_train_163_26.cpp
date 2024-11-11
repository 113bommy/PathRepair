#include <bits/stdc++.h>
const int N = 2010;
long long n, k, p;
long long a[N], b[N], left[N], right[N];
std::pair<long long, long long> pp[N];
std::priority_queue<int> pq;
bool check(long long mid) {
  memset(left, 0x7f, sizeof(left));
  memset(right, 0, sizeof(right));
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < k; ++j) {
      if (std::abs(a[i] - b[j]) + std::abs(b[j] - p) <= mid) {
        left[i] = std::min(left[i], j);
        right[i] = std::max(right[i], j);
      }
    }
  }
  for (long long i = 0; i < n; ++i) {
    if (left[i] > right[i]) {
      return false;
    }
    pp[i] = {left[i], right[i]};
  }
  std::sort(pp, pp + n);
  while (!pq.empty()) {
    pq.pop();
  }
  for (int i = 0, j = 0; i < k; ++i) {
    while (j < n && pp[j].first == i) {
      pq.push(-pp[j++].second);
    }
    if (!pq.empty()) {
      if (-pq.top() < i) {
        return false;
      }
      pq.pop();
    }
  }
  return pq.empty();
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &k, &p);
  for (long long i = 0; i < n; ++i) {
    scanf("%I64d", &a[i]);
  }
  std::sort(a, a + n);
  for (long long j = 0; j < k; ++j) {
    scanf("%I64d", &b[j]);
  }
  std::sort(b, b + k);
  long long left = 0, right = 1e10;
  while (left < right) {
    long long mid = left + right >> 1;
    if (check(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return printf("%I64d\n", left), 0;
}
