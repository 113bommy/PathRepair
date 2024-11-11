#include <bits/stdc++.h>
const int MAX = 5e5;
int w[MAX];
int N, k;
bool ok_min(int min) {
  long long cnt(0);
  for (int i(0); i < N; ++i)
    if (w[i] < min) cnt += min - w[i];
  return cnt <= k;
}
bool ok_max(int max) {
  long long cnt(0);
  for (int i(0); i < N; ++i)
    if (w[i] > max) cnt += w[i] - max;
  return cnt <= k;
}
int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> N >> k;
  long long tot = 0;
  for (int i(0); i < N; ++i) {
    std::cin >> w[i];
    tot += w[i];
  }
  int left(0), right(1e9);
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (ok_min(mid))
      left = mid;
    else
      right = mid;
  }
  int min_bound = left;
  int left2(0), right2(1e9);
  while (left2 + 1 < right2) {
    int mid = (left2 + right2) / 2;
    if (ok_max(mid))
      right2 = mid;
    else
      left2 = mid;
  }
  int max_bound = left2 + 1;
  if (min_bound > max_bound)
    std::cout << tot % 2 << "\n";
  else
    std::cout << max_bound - min_bound << "\n";
}
