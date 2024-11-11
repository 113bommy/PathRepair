#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int a[105], b[105];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 1)
    a[0] = 1;
  else if (n == 2) {
    a[0] = 3;
    a[1] = 4;
  } else if (n % 2) {
    a[0] = 2;
    for (int i = 1; i < n - 1; i++) {
      a[i] = 1;
    }
    a[n - 1] = (n + 1) / 2;
  } else {
    for (int i = 0; i < n - 1; i++) {
      a[i] = 1;
    }
    a[n - 1] = (n - 2) / 2;
  }
  if (m == 1)
    b[0] = 1;
  else if (m == 2) {
    b[0] = 3;
    b[1] = 4;
  } else if (m % 2) {
    b[0] = 2;
    for (int i = 1; i < m - 1; i++) {
      b[i] = 1;
    }
    b[m - 1] = (m + 1) / 2;
  } else {
    for (int i = 0; i < m - 1; i++) {
      b[i] = 1;
    }
    b[m - 1] = (m - 2) / 2;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i] * b[j] << " ";
    }
    cout << endl;
  }
}
