#include <bits/stdc++.h>
template <class X, class Y>
X& remin(X& x, Y y) {
  return x = (y < x ? y : x);
}
const int NMAX = 2020, INF = (int)1e9;
int n, k, arr[NMAX], minK[NMAX][NMAX];
const bool debug = 0;
bool check(int x) {
  std::fill(&minK[0][0], &minK[0][0] + NMAX * NMAX, INF);
  minK[1][1] = 0;
  for (int prefix = 2; prefix <= n; prefix++) {
    std::cerr&& debug&& std::cerr << "prefix = " << prefix << std::endl;
    for (int last = 0; last <= prefix; last++) {
      std::cerr&& debug&& std::cerr << "\tlast=" << last << ", minK"
                                    << minK[prefix][last] << std::endl;
    }
    for (int last = 0; last <= prefix; last++) {
      remin(minK[prefix][last], minK[prefix - 1][last] + 1);
    }
    const int last = prefix;
    remin(minK[prefix][last], prefix - 1);
    for (int prev = 1; prev < prefix; prev++) {
      if (std::abs(arr[last] - arr[prev]) <= (last - prev + 0LL) * x) {
        remin(minK[prefix][last], minK[prefix - 1][prev]);
      }
    }
    std::cerr&& debug&& std::cerr << "prefix = " << prefix << std::endl;
    for (int last = 1; last <= prefix; last++) {
      std::cerr&& debug&& std::cerr << "\tlast=" << last << ", minK"
                                    << minK[prefix][last] << std::endl;
    }
  }
  return *std::min_element(minK[n] + 1, minK[n] + n + 1) <= k;
}
int solve() {
  int low = -1, high = (int)2e9;
  while (high - low > 1) {
    int mid = (low + high) / 2;
    if (check(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  return high;
}
int main() {
  while (std::cin >> n >> k) {
    for (int i = 1; i <= n; i++) std::cin >> arr[i];
    std::cout << solve() << std::endl;
  }
  return 0;
}
