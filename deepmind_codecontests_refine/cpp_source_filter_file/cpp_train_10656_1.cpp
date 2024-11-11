#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  bool flag = false;
  cin >> n;
  long int a[100005], b[100005], min, max;
  cin >> a[1] >> b[1];
  min = a[1];
  max = b[1];
  for (i = 2; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (min > a[i]) min = a[i];
    if (max < a[i]) max = a[i];
  }
  for (i = 1; i <= n; i++) {
    if ((min == a[i]) && (max == b[i])) {
      flag = true;
      break;
    }
  }
  if (flag)
    cout << i;
  else
    cout << -1;
  return 0;
}
