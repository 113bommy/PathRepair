#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m;
  cin >> n >> m;
  int a[m];
  int b[101] = {0};
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  int t = 0;
  int d = 1;
  int sum = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = 0; j < 101; j++) {
      sum += (b[j] / d);
      if (sum >= n) break;
    }
    if (sum < n) {
      break;
    } else {
      ans = d;
      d++;
    }
  }
  cout << ans;
  return 0;
}
