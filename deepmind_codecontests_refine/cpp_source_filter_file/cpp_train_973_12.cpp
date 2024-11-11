#include <bits/stdc++.h>
using namespace std;
int mat[101][101];
vector<int> v;
int i, j, n;
bool a, b;
int main() {
  cin >> n;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) cin >> mat[i][j];
  for (i = 0; i < n; i++) {
    int act = 0;
    for (j = 0; j < n; j++)
      if (mat[i][j] != -1) act ^= mat[i][j];
    v.push_back(act);
  }
  for (i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
  return 0;
}
