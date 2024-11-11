#include <bits/stdc++.h>
using namespace std;
int x[1000005];
int y[1000005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int j = 0; j < n; j++) {
    cin >> y[j];
  }
  int res = 0;
  int sum = 0;
  int i = 0;
  int j = 0;
  while (i < n && j < m) {
    if (sum == 0) {
      res += 1;
      sum += x[i];
      i++;
    } else if (sum > 0) {
      sum -= y[j];
      j++;
    } else if (sum < 0) {
      sum += x[i];
      i++;
    }
  }
  cout << res << endl;
  return 0;
}
