#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<bool> peak(n, false);
    for (int i = 1; i < n - 1; ++i) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        peak[i] = true;
      }
    }
    vector<int> sum_of_peak(n, 0);
    for (int i = 1; i < n; ++i) {
      sum_of_peak[i] = sum_of_peak[i - 1];
      if (peak[i]) {
        ++sum_of_peak[i];
      }
    }
    int max_of_peak = 0;
    int min_l = 0;
    for (int i = 0; i < n - k + 1; ++i) {
      int l = max(0, i - 1);
      int r = i + k - 1;
      int current_sum = sum_of_peak[r] - sum_of_peak[l];
      if (peak[i]) {
        --current_sum;
      }
      if (peak[r]) {
        --current_sum;
      }
      if (current_sum > max_of_peak) {
        max_of_peak = current_sum;
        min_l = i;
      }
    }
    cout << max_of_peak + 1 << ' ' << min_l + 1 << '\n';
  }
  return 0;
}
