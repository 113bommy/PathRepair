#include <bits/stdc++.h>
using namespace std;
int primes[17] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                  29, 31, 37, 41, 43, 47, 53, 59};
pair<int, int> dp[101][1 << 17];
int n;
int a[100];
int num_mask[60];
void calculate_number_masks() {
  for (int i = 2; i <= 59; i++) {
    int mask = 0;
    int temp = i;
    for (int j = 0; j < 17; j++) {
      while (temp % primes[j] == 0) {
        mask = mask | (1 << j);
        temp /= primes[j];
      }
    }
    num_mask[i] = mask;
  }
}
pair<int, int> solve(int index, int mask) {
  if (index == n) {
    return make_pair(0, 0);
  }
  if (dp[index][mask].first != -1) {
    return dp[index][mask];
  }
  int i;
  int ans = INT_MAX;
  int min_value = -1;
  for (i = 1; i <= 2 * a[index] - 1; i++) {
    int tmask = mask;
    if ((mask & num_mask[i]) == 0) {
      int temp = abs(i - a[index]) + solve(index + 1, mask | num_mask[i]).first;
      if (ans > temp) {
        ans = temp;
        min_value = i;
      }
    }
  }
  dp[index][mask] = make_pair(ans, min_value);
  return dp[index][mask];
}
int main() {
  ios_base::sync_with_stdio(false);
  int i, j, k, m, t, l, r, q, x;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  calculate_number_masks();
  pair<int, int> start = solve(0, 0);
  cout << start.second << " ";
  int mask = 0;
  mask |= num_mask[start.second];
  for (i = 1; i < n; i++) {
    pair<int, int> temp = dp[i][mask];
    cout << temp.second << " ";
    mask |= num_mask[temp.second];
  }
  return 0;
}
