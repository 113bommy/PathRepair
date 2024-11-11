#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n];
  if (n % 2 == 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  vector<int> a, b;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1)
      a.push_back(i);
    else {
      a.push_back(2 * n - (i - 2));
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 1)
      cout << a[i] + 1 << ' ';
    else
      cout << a[i] - 1 << ' ';
  }
  cout << endl;
  return 0;
}
