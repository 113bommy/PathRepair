#include <bits/stdc++.h>
int a[1005][3];
int b[1005][3];
using namespace std;
int main() {
  int flag = 1;
  int v = 1;
  int n, i, j, k;
  cin >> n;
  double sum = 0, num = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i][1] >> a[i][2];
    sum += a[i][1];
    num += a[i][2];
  }
  for (i = 1; i <= n; i++) {
    cin >> b[i][1] >> b[i][2];
    sum += b[i][1];
    num += b[i][2];
  }
  num = num / n;
  sum = sum / n;
  cout << sum << " " << num << endl;
  return 0;
}
