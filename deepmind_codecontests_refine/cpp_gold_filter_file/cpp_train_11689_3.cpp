#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, maximum, minimum;
  int a[5], b[5];
  cin >> n;
  cin >> a[0] >> a[1] >> a[2];
  cin >> b[0] >> b[1] >> b[2];
  maximum = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
  minimum = max(
      max(max(a[0] - b[0] - b[2], a[1] - b[0] - b[1]), a[2] - b[1] - b[2]), 0);
  cout << minimum << " " << maximum << endl;
  return 0;
}
