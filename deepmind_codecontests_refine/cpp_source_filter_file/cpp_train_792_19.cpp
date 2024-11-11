#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char arr[102][102];
  vector<string> row, col;
  string coun = "";
  for (int i = 0; i < n; i++) {
    coun = "";
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      coun += arr[i][j];
    }
    row.push_back(coun);
  }
  for (int i = 0; i < n; i++) {
    coun = "";
    for (int j = 0; j < m; j++) {
      coun += arr[j][i];
    }
    col.push_back(coun);
  }
  string res = "";
  for (int i = 0; i < n; i++) {
    string r = row[i];
    for (int j = 0; j < m; j++) {
      string c = col[j];
      int sum = count(r.begin(), r.end(), arr[i][j]) +
                count(c.begin(), c.end(), arr[i][j]);
      if (sum == 2) res += arr[i][j];
    }
  }
  return cout << res << "\n", 0;
}
