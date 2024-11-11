#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int x[100];
  int y[100];
  float sum;
  float final_sum;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 1; i < n; i++) {
    sum += sqrt(pow(x[i] - x[i - 1], 2) + pow(y[i] - y[i - 1], 2));
  }
  final_sum = sum * k / 50;
  cout << std::setprecision(9) << final_sum;
  return 0;
}
