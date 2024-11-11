#include <bits/stdc++.h>
using namespace std;
void print(int n) { cout << n << ' '; }
int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  vector<int> sum(n);
  vector<int> ways(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
    if (i > 0)
      sum[i] = sum[i - 1] + nums[i];
    else
      sum[0] = nums[0];
  }
  int total = sum[n - 1];
  int subtotal = total / 3;
  if (total % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0)
      ways[i] = ways[i - 1] + (sum[i] == subtotal);
    else
      ways[0] = (sum[0] == subtotal);
  }
  int counter = 0;
  for (int i = 1; i < n - 1; ++i) {
    if (sum[i] == subtotal * 2) {
      counter += ways[i - 1];
    }
  }
  cout << counter << endl;
  return 0;
}
