#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int mini = 100000, temp_min;
  vector<int> v;
  v.push_back(2);
  int x = 2;
  bool tinka = true;
  while (1) {
    tinka = true;
    for (int i = 2; i < sqrt(x) + 1; i++) {
      if (x % i == 0) {
        tinka = false;
        break;
      }
    }
    if (tinka) {
      v.push_back(x);
    }
    x++;
    if (x == 100000) break;
  }
  int A[500][500];
  int n, m;
  cin >> n >> m;
  vector<int>::iterator it;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
      it = lower_bound(v.begin(), v.end(), A[i][j]);
      A[i][j] = *it - A[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    temp_min = 0;
    for (int j = 0; j < m; j++) temp_min += A[i][j];
    mini = min(mini, temp_min);
  }
  for (int i = 0; i < m; i++) {
    temp_min = 0;
    for (int j = 0; j < n; j++) temp_min += A[j][i];
    mini = min(mini, temp_min);
  }
  cout << mini;
  return 0;
}
