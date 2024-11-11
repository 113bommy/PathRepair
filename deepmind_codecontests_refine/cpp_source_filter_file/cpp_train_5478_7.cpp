#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (a[0] == a[n / 2 - 1] && a[n / 2] == a[n - 1] && a[0] != a[n - 1]) {
    cout << "YES " << endl;
    cout << a[0] << " " << a[n - 1] << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
