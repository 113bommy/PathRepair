#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> fence;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    fence.push_back(a);
  }
  int fir_sum_k = 0;
  int store_idx = 1, store_sum = 0;
  for (int i = 0; i < k; i++) fir_sum_k += fence[i];
  store_sum = fir_sum_k;
  for (int i = 1; i < n - k + 1; i++) {
    int minus = fence[i - 1];
    int plus = fence[i + k - 1];
    store_sum += plus;
    store_sum -= minus;
    if (fir_sum_k > store_sum) {
      fir_sum_k = store_sum;
      store_idx = i + 1;
    }
  }
  cout << store_idx << endl;
  return 0;
}
