#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, count = 0;
    cin >> n >> m;
    string arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < (m - 1); i++) {
      if (arr[n - 1][i] != 'R') count++;
    }
    for (int i = 0; i < (n - 1); i++) {
      if (arr[i][m - 1] != 'D') count++;
    }
    cout << count << endl;
  }
}
