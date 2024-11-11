#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    vector<long long> peak(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    long long max = 0;
    peak[0] = 0;
    for (int i = 1; i < n - 1; i++) {
      peak[i] = max;
      if (vec[i] > vec[i - 1] && vec[i] > vec[i + 1]) max++;
    }
    peak[n - 1] = max;
    int l = 0;
    max = 0;
    for (int i = 0; i <= n - k; i++) {
      if (peak[i + k - 1] - peak[i] > max) {
        l = i;
        max = peak[i + k - 1] - peak[i + 1];
      }
    }
    cout << max + 1 << " " << l + 1 << endl;
  }
  return 0;
}
