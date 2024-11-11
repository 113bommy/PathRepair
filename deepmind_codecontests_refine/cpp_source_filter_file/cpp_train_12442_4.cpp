#include <bits/stdc++.h>
using namespace std;
int n, m, a[105][105], mn, mx;
vector<int> v;
int help(int b[], int m) {
  mn = b[0];
  for (int i = 0; i < m; i++) {
    if (b[i] < mn) mn = b[i];
  }
  return mn;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  for (int i = 0; i < 3; i++) {
    v.push_back(help(a[i], m));
  }
  mx = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i] > mx) {
      mx = v[i];
    }
  }
  cout << mx << endl;
  return 0;
}
