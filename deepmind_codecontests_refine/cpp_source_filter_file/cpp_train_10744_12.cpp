#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long int a[3];
  cin >> t;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 3; j++) cin >> a[j];
    sort(a, a + 3);
    if ((a[2] - a[1]) > 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
