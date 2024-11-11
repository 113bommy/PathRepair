#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, i, flag = 0;
  cin >> n;
  double a[n];
  set<double> x;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n - 2; i++) {
    if (((a[i] + a[i + 1]) > a[i + 2]) && ((a[i + 1] + a[i + 2]) > a[i]) &&
        ((a[i] + a[i + 2]) > a[i + 1])) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
