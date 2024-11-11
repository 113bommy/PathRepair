#include <bits/stdc++.h>
using namespace std;
int main() {
  int i;
  int n;
  int sub;
  int a[1000];
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sub = a[1] - a[0];
  for (i = 2; i < n; i++) {
    if (sub == a[i] - a[i - 1])
      ;
    else {
      cout << a[i + 1] << endl;
      return 0;
    }
  }
  cout << a[n - 1] + sub << endl;
  return 0;
}
