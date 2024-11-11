#include <bits/stdc++.h>
using namespace std;
const int MAX = 100 + 100;
int a[MAX][MAX];
vector<int> v;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) {
    bool h = 1;
    for (int j = 0; j < n; j++)
      if (a[i][j] == 1 || a[i][j] == 3) {
        h = 0;
        break;
      }
    if (h) v.push_back(i);
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
  return 0;
}
