#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<int> v, u;
  int count = 0;
  int sum1 = 0, sum2 = 0;
  cin >> n;
  int a[31][31] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum1 = sum1 + a[i][j];
    }
    v.push_back(sum1);
    sum1 = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum2 = sum2 + a[j][i];
    }
    u.push_back(sum2);
    sum2 = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i] < u[j]) {
        count++;
      }
    }
  }
  cout << count << endl;
}
