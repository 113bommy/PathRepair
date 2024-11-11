#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, cur_mex;
  cin >> t;
  vector<vector<int> > v, res;
  vector<int> k;
  v.resize(t);
  k.resize(t);
  res.resize(t);
  for (int i = 0; i < t; i++) {
    cin >> n;
    v[i].resize(n);
    vector<int> mex;
    mex.resize(n + 1);
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
    bool cond = false;
    for (int j = 1; j < n; j++) {
      if (v[i][j - 1] > v[i][j]) {
        cond = true;
        break;
      }
    }
    k[i] = 0;
    while (cond && k[i] <= 2 * n) {
      k[i]++;
      for (int j = 0; j < n + 1; j++) {
        mex[j] = 0;
      }
      for (int j = 0; j < n; j++) {
        mex[v[i][j]] = 1;
      }
      for (int j = 0; j < n + 1; j++) {
        if (mex[j] == 0) {
          cur_mex = j;
          break;
        }
      }
      if (cur_mex != n) {
        v[i][cur_mex] = cur_mex;
        res[i].push_back(cur_mex + 1);
      } else {
        for (int k = 0; k < n; k++) {
          if (v[i][k] != k) {
            v[i][k] = cur_mex;
            res[i].push_back(k + 1);
            break;
          }
        }
      }
      cond = false;
      for (int j = 1; j < n; j++) {
        if (v[i][j - 1] > v[i][j]) {
          cond = true;
          break;
        }
      }
    }
  }
  for (int i = 0; i < t; i++) {
    cout << k[i] << endl;
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}
