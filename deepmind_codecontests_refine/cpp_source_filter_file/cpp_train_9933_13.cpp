#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a;
  int n, k, c, sum = 0, min = INT_MAX, index;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> c;
    a.push_back(c);
  }
  for (int i = 0; i < k; i++) sum += a[i];
  if (sum < min) {
    min = sum;
    index = 1;
  }
  for (int i = 1; i < n - k; i++) {
    sum = sum - a[i - 1] + a[i + k - 1];
    if (sum < min) {
      min = sum;
      index = i + 1;
    }
  }
  cout << index << endl;
  return 0;
}
