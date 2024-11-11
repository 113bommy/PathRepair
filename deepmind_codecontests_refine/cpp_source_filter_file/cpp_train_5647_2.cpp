#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int x = 0; x < t; x++) {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0)
          cout << "B";
        else
          cout << "W";
      }
      cout << endl;
    }
    continue;
  }
}
