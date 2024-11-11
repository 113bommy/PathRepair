#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  int n_sum = 0;
  int min_sum = 2147483647;
  int iter;
  if (n % k != 0)
    iter = n / k + 1;
  else
    iter = n / k;
  vector<int> b(iter);
  for (int i = 0; i < iter; i++) {
    b[i] = i * k - 1;
  }
  for (int i = 0; i < n / 2 + 1; i++) {
    sum = 0;
    for (int j = 0; j < iter; j++) {
      b[j] = b[j] + 1;
      if (b[j] >= n) b[j] -= n;
      sum += a[b[j]];
    }
    if (min_sum > sum) {
      min_sum = sum;
      n_sum = i;
    }
  }
  cout << n_sum + 1;
  return 0;
}
