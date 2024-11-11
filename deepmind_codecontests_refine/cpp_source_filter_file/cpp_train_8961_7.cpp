#include <bits/stdc++.h>
using std::cin;
using std::cout;
int main() {
  int n;
  cin >> n;
  int nums[n + 1];
  for (int i = 1; i < n + 1; i++) {
    cin >> nums[i];
  }
  int results[n];
  for (int k = 0; k < n; k++) {
    bool marked[n];
    for (int i = 0; i < n; i++) {
      marked[i] = false;
    }
    int index = k + 1;
    while (!marked[index]) {
      marked[index] = true;
      index = nums[index];
    }
    results[k] = index;
  }
  for (int i = 0; i < n; i++) {
    cout << results[i] << " ";
  }
}
