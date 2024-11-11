#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long arr[n], arr2[m];
  if (n == 1)
    arr[0] = {1};
  else if (n == 2)
    arr[0] = 3, arr[1] = 4;
  else if (n % 2) {
    arr[0] = (n + 1) / 2;
    for (long long i = 1; i < n - 1; i++) {
      arr[i] = 1;
    }
    arr[n - 1] = 2;
  } else {
    arr[0] = (n - 2) / 2;
    for (long long i = 1; i < n; i++) {
      arr[i] = 1;
    }
  }
  if (m == 1)
    arr2[0] = {1};
  else if (m == 2)
    arr2[0] = 3, arr2[1] = 4;
  else if (m % 2) {
    arr2[0] = (m + 1) / 2;
    for (long long i = 1; i < m - 1; i++) {
      arr2[i] = 1;
    }
    arr2[m - 1] = 2;
  } else {
    arr2[0] = (m - 2) / 2;
    for (long long i = 1; i < m; i++) {
      arr2[i] = 1;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cout << arr[i] * arr2[j] << " ";
    }
    cout << "\n";
  }
}
