#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int arr[200010], sum[200010];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  sum[0] = 0;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];
  int mini = 1e9, pos = -1;
  for (int i = k; i <= n; i++) {
    if (mini > sum[i] - sum[i - k]) {
      pos = k;
      mini = sum[i] - sum[i - k];
    }
  }
  cout << pos << endl;
  return 0;
}
