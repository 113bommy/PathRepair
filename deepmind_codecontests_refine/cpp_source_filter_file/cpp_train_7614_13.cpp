#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, m = 0, h = 0;
  cin >> n >> m >> h;
  int* y = new int[n];
  int* x = new int[m];
  for (int i = 0; i < m; ++i) {
    cin >> y[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<int> vec2(0);
  vector<vector<int> > vec1(n, vec2);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int temp = 0;
      cin >> temp;
      vec1[i].push_back(temp);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      vec1[i].at(j) = vec1[i].at(j) * (x[i] > y[j] ? y[j] : x[i]);
      cout << vec1[i][j];
    }
    cout << endl;
  }
  delete[] x;
  delete[] y;
  return 0;
}
