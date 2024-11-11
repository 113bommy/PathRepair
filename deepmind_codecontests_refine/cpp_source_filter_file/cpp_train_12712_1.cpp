#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> sum(n + 1, 0);
  for (int x, i = 0; i < n; i++) {
    cin >> x;
    sum[i + 1] = sum[i] + x;
  }
  int max = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (sum[j] - sum[i] >= 100 * (j - i) && j - i >= max) max = j - i;
    }
  }
  cout << max << endl;
  return 0;
}
