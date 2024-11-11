#include <bits/stdc++.h>
using namespace std;
template <typename T>
T ABS(const T& val) {
  return val < 0 ? -val : val;
}
const int MAXN = 1e5 + 11;
const int MAXVAL = 1e4 + 1;
int nums[MAXN];
int N;
int main() {
  while (scanf("%d", &N) > 0) {
    int best = 1e9;
    for (int i = 0; i < N; ++i) {
      scanf("%d", &nums[i]);
      if (i) best = min(best, 1 + nums[i] * nums[i]);
    }
    for (int i = 1; i < N; ++i) {
      int psum = 0;
      for (int len = 1; i + len <= N && len < 2000; ++len) {
        psum += nums[i + len - 1];
        if (len * len > best) break;
        if (psum > MAXVAL || -psum > MAXVAL) continue;
        best = min(best, len * len + psum * psum);
      }
    }
    printf("%d\n", best);
  }
  return 0;
}
