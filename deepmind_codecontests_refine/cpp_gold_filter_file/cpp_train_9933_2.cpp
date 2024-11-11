#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, low = 0, sum = 0, p;
  cin >> n >> k;
  int h[n];
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < k; i++) {
    low = low + h[i];
  }
  for (int i = 0; i < k; i++) {
    sum = sum + h[i];
  }
  for (int i = 0; i < k; i++) {
    if (sum <= low) {
      low = sum;
      p = 1;
    }
  }
  for (int i = 1; i < (n - k + 1); i++) {
    sum = sum - h[i - 1] + h[i + k - 1];
    if (sum <= low) {
      low = sum;
      p = i + 1;
    }
  }
  cout << p;
  return 0;
}
