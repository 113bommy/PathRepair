#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum{0}, gsum{0}, ones{0};
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    ones += v[i];
  }
  if (ones == n) {
    cout << n - 1;
    return 0;
  }
  for (int temp : v) {
    if (sum == 0 && temp == 1)
      continue;
    else if (sum <= 0 && temp == 0)
      sum = 1;
    else if (temp == 0)
      sum++;
    else if (temp == 1)
      sum--;
    gsum = gsum < sum ? sum : gsum;
  }
  cout << gsum + ones;
  return 0;
}
