#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long a[n];
  long long sum = 0;
  long mi = 1000000001;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n, greater<int>());
  for (int i = 0; i < n; i++) {
    if (!mi) {
      if (mi <= a[i]) {
        sum += (mi - 1);
        mi = mi - 1;
      } else {
        sum += a[i];
        mi = a[i];
      }
    }
  }
  cout << sum << endl;
}
