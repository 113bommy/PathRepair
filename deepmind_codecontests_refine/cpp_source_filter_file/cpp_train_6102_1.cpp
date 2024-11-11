#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] % 2 != 0 && a[0] % 2 != 0) {
    if (n % 2 != 0) {
      cout << "Yes";
    } else {
      cout << "No";
    }
  } else {
    cout << "No";
  }
  return 0;
}
