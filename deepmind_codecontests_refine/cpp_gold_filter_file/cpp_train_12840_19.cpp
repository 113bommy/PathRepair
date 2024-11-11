#include <bits/stdc++.h>
using namespace std;
int sum[100001];
int main() {
  int n, i, cnt = 0;
  cin >> n;
  int a[n + 1];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  for (i = 1; i < n; i++) {
    if (sum[i] == (sum[n] - sum[i])) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
