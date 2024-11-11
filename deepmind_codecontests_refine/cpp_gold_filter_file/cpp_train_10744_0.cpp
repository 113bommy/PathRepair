#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a[3];
    int i = 0;
    for (i = 0; i < 3; i++) cin >> a[i];
    sort(a, a + 3);
    int c = a[2] - a[0] - a[1];
    if (c < 2)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
