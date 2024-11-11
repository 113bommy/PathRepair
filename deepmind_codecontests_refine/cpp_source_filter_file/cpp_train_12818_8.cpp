#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y;
  cin >> n >> x >> y;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int count = 0;
  if (x > y)
    cout << n << endl;
  else {
    for (long long int i = 0; i < n; i++) {
      if (a[i] <= x) count++;
    }
    cout << count / 2 << endl;
  }
  return 0;
}
