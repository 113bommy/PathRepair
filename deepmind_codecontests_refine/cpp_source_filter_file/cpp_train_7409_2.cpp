#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[2000];
  long int n, d, k = 0;
  cin >> n >> d;
  for (int i = 1; i < 2000; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] >= a[i + 1]) {
      int x = (a[i] - a[i + 1]) / d;
      a[i + 1] += (x + 1) * d;
      k += (x + 1);
    }
  }
  cout << k << endl;
  return 0;
}
