#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int main() {
  int n, k, a, b;
  a = INT_MIN;
  b = INT_MAX;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    a = max(a, arr[i]);
    b = min(b, arr[i]);
  }
  if (a > k) {
    int x = a - b;
    if (a > 2 * b && x > k) {
      cout << "NO" << '\n';
    } else {
      vector<vector<int>> p(n);
      cout << "YES" << '\n';
      for (int i = 0; i < n; i++) {
        for (int j = 1; j <= arr[i]; j++) {
          int r = j;
          r %= k;
          if (r == 0) r = k;
          p[i].push_back(r);
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].size(); j++) {
          cout << p[i][j] << " ";
        }
        cout << '\n';
      }
    }
  } else {
    vector<vector<int>> p(n);
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= arr[i]; j++) {
        p[i].push_back(j);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < p[i].size(); j++) {
        cout << p[i][j] << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
