#include <bits/stdc++.h>
using namespace std;
int main() {
  double maxi = 0, sum = 0, n, b;
  cin >> n >> b;
  std::vector<double> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    maxi = max(maxi, v[i]);
    sum += v[i];
  }
  sum = (sum + b) / n;
  if (maxi > b) {
    cout << -1;
  } else {
    for (int i = 0; i < n; i++) {
      printf("%.6lf\n", sum - v[i]);
    }
  }
}
