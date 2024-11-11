#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, cnt = 0;
  cin >> n;
  int a[n + 1][n + 1];
  vector<int> v;
  vector<int> v1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int no = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 1 || a[i][j] == 3) {
        no = 1;
      }
    }
    if (no != 1) {
      v.push_back(i + 1);
    }
    no = 1;
  }
  if (v.size() == 0) {
    cout << "0" << endl;
    return 0;
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}
