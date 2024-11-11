#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  vector<int> v[100];
  int n;
  cin >> n;
  int ar[1000];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for (int i = 0; i < n; i++) {
    int t;
    for (int j = 0; j < ar[i]; j++) {
      cin >> t;
      v[i].push_back(t);
    }
  }
  int m = 10000;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < v[i].size(); j++) {
      sum += v[i][j] * 5;
    }
    sum = sum + v[i].size() * 15;
    if (sum < m) {
      m = sum;
    }
  }
  cout << m;
  return 0;
}
