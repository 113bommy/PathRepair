#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c, d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != 0) c.push_back(a[i]);
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] != 0) d.push_back(b[i]);
  }
  for (int i = 0; i < n - 1; i++) c.push_back(a[i]);
  int i = 0;
  for (; i < n; i++)
    if (c[i] == d[0]) break;
  for (int j = i; j < i + n - 1; j++)
    if (c[j] != d[j - i]) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  return 0;
}
