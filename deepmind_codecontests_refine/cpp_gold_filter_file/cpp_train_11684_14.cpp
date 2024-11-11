#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, ind;
  cin >> t;
  while (t--) {
    cin >> n;
    ind = -1;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] % 2 == 0) ind = i;
    }
    if (ind != -1)
      cout << "1\n" << ind + 1 << '\n';
    else if (n > 1)
      cout << "2\n1 2\n";
    else
      cout << "-1\n";
  }
}
