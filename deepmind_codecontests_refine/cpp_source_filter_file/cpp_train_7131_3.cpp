#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 155, inf = 0x3f3f3f3f;
int left_dp[2][kMaxN][kMaxN * kMaxN];
int right_dp[2][kMaxN][kMaxN * kMaxN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k, s;
  cin >> n >> k >> s;
  vector<int> els(n);
  for (int i = 0; i < n; i += 1) {
    cin >> els[i];
  }
  for (int j = 0; j <= n; j += 1) {
    for (int l = 0; l <= n * n; l += 1) {
      right_dp[0][j][l] = +inf;
      right_dp[0][0][l] = 0;
    }
  }
  for (int i = k - 1; i >= 0; i -= 1) {
    for (int num_taken = 0; num_taken <= k - 1 - i; num_taken += 1) {
      for (int swaps = 0; swaps <= k * k; swaps += 1) {
        left_dp[1][num_taken][swaps] = left_dp[0][num_taken][swaps];
      }
    }
    for (int num_taken = 0; num_taken <= k - 1 - i; num_taken += 1) {
      for (int swaps = 0; swaps <= k * k; swaps += 1) {
        int swap_here = k - 1 - i - num_taken;
        auto& c = left_dp[0][num_taken + 1][swaps + swap_here];
        c = max(c, els[i] + left_dp[1][num_taken][swaps]);
        c = max(c, left_dp[1][num_taken + 1][swaps + swap_here]);
      }
    }
  }
  for (int i = k; i < n; i += 1) {
    for (int num_taken = 0; num_taken <= i - k + 1; num_taken += 1) {
      for (int swaps = 0; swaps <= (n - k) * (n - k); swaps += 1) {
        right_dp[1][num_taken][swaps] = right_dp[0][num_taken][swaps];
      }
    }
    for (int num_taken = 0; num_taken <= i - k; num_taken += 1) {
      for (int swaps = 0; swaps <= (n - k) * (n - k); swaps += 1) {
        int swap_here = i - k - num_taken;
        auto& c = right_dp[0][num_taken + 1][swaps + swap_here];
        c = min(c, els[i] + right_dp[1][num_taken][swaps]);
        c = min(c, right_dp[1][num_taken + 1][swaps + swap_here]);
      }
    }
  }
  int left_sum = 0;
  for (int i = 0; i < k; i += 1) {
    left_sum += els[i];
  }
  int ans = +inf;
  for (int num_taken = 0; num_taken <= k; num_taken += 1) {
    int remaining_swaps = k - num_taken * num_taken;
    if (remaining_swaps < 0) {
      continue;
    }
    for (int left_swaps = 0; left_swaps <= k * k; left_swaps += 1) {
      for (int right_swaps = 0; right_swaps <= (n - k) * (n - k);
           right_swaps += 1) {
        int c_swaps = remaining_swaps - left_swaps - right_swaps;
        if (c_swaps < 0) {
          break;
        }
        ans = min(ans, left_sum - left_dp[0][num_taken][left_swaps] +
                           right_dp[0][num_taken][right_swaps]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
