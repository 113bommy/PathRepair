#include <bits/stdc++.h>
using namespace std;
int x[100][100], n, c, z;
vector<int> v;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> x[i][j];
  for (int i = 0; i < n; i++) {
    c = 0;
    for (int j = 0; j < n; j++) {
      if (x[i][j] != 3 && x[i][j] != 1) c++;
    }
    if (c == n) v.push_back(i), z++;
  }
  cout << z << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] + 1 << " ";
}
