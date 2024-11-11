#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > v(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  vector<vector<int> > res(n, vector<int>(m));
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (i == 0)
        res[i][j] = 0;
      else {
        if (v[i][j] >= v[i - 1][j])
          res[i][j] = res[i - 1][j];
        else
          res[i][j] = i;
      }
    }
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int curres = 0;
    for (int j = 0; j < m; j++) {
      int c = res[i][j];
      if (res[i][j] < res[i][curres]) {
        curres = j;
      }
    }
    ans[i] = res[i][curres];
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    if (ans[r] <= l)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
