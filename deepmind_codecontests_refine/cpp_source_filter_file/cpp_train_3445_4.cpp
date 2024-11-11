#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  long long flag = 0;
  long long a[n];
  long long b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    flag ^= a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    flag ^= b[i];
  }
  if (flag != 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < m - 1; i++) flag ^= b[i];
  flag ^= a[n - 1];
  for (int i = 0; i < n - 1; i++) {
    cout << a[i] << " ";
    for (int j = 0; j < m - 1; j++) {
      cout << 0 << " ";
    }
    cout << endl;
  }
  cout << flag << " ";
  for (int i = 1; i < m; i++) {
    cout << b[i];
    if (i == m - 1)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
