#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[300000];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (a[i] & 1 == 0) {
      a[i] >>= 1;
    }
    while (a[i] % 3 == 0) {
      a[i] /= 3;
    }
  }
  int same = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] != same) {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
}
