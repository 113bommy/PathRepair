#include <bits/stdc++.h>
using namespace std;
int arr[27];
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> rows;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    rows.push_back(row);
  }
  int minx = 1e6, maxx = 0, miny = 1e6, maxy = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)rows[i].size(); j++) {
      if (rows[i][j] == 'X') {
        miny = min(miny, i);
        maxy = max(maxy, i);
        minx = min(minx, j);
        maxx = max(maxx, j);
        count++;
      }
    }
  }
  int res = ((maxx - minx) + 1) * ((maxy - miny) + 1);
  if (res == count) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  int pause;
  cin >> pause;
  return 0;
}
