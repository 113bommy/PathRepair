#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char temp = 0;
  int sum[7];
  memset(sum, 0, sizeof(sum));
  ;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 7; ++j) {
      cin >> temp;
      sum[j] = sum[j] + temp - 48;
    }
  }
  int ans = 1;
  for (int k = 0; k < 7; ++k) {
    ans = max(ans, sum[k]);
  }
  cout << ans;
  return 0;
}
