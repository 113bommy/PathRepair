#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio;
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<double>> w(n, vector<double>(n));
  vector<vector<double>> a(n, vector<double>(n));
  vector<vector<double>> b(n, vector<double>(n));
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> w[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << (w[i][j] + w[j][i]) / 2 << " ";
    }
    cout << endl;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << (w[i][j] - w[j][i]) / 2 << " ";
    }
    cout << endl;
  }
  return 0;
}
