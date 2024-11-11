#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    vector<int> a(3);
    int mx = -1000000;
    for (int j = 0; j < 3; j++) {
      cin >> a[j];
      if (a[j] >= mx) mx = a[j];
    }
    cin >> n;
    for (int j = 0; j < 3; j++)
      if (a[j] != mx) n -= mx - a[j];
    if (n < 0)
      cout << "NO" << endl;
    else if (n % 3 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
