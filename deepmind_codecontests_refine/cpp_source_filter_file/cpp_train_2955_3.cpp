#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    if ((a[i + 1] - a[i]) * (a[i] - a[0]) < 0) {
      cout << "3\n1 " << i + 1 << ' ' << i + 2 << endl;
      return 0;
    }
  }
  cout << "0\n";
  return 0;
}
