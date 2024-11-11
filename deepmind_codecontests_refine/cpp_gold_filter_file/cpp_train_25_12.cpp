#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    vector<int> ans1;
    vector<int> ans2;
    int res = 0;
    for (int x = 0; x < n; x++)
      for (int y = 0; y < n; y++) cin >> a[x][y];
    int mia, mib;
    mia = ((a[0][1] == '0') + (a[1][0] == '0'));
    mib = ((a[n - 1][n - 2] == '0') + (a[n - 2][n - 1] == '0'));
    if (mia >= mib) {
      if (a[0][1] != '0') {
        res++;
        ans1.push_back(1);
        ans2.push_back(2);
      }
      if (a[1][0] != '0') {
        res++;
        ans1.push_back(2);
        ans2.push_back(1);
      }
      if (a[n - 1][n - 2] != '1') {
        res++;
        ans1.push_back(n);
        ans2.push_back(n - 1);
      }
      if (a[n - 2][n - 1] != '1') {
        res++;
        ans1.push_back(n - 1);
        ans2.push_back(n);
      }
    } else {
      if (a[0][1] != '1') {
        res++;
        ans1.push_back(1);
        ans2.push_back(2);
      }
      if (a[1][0] != '1') {
        res++;
        ans1.push_back(2);
        ans2.push_back(1);
      }
      if (a[n - 1][n - 2] != '0') {
        res++;
        ans1.push_back(n);
        ans2.push_back(n - 1);
      }
      if (a[n - 2][n - 1] != '0') {
        res++;
        ans1.push_back(n - 1);
        ans2.push_back(n);
      }
    }
    cout << res << endl;
    for (int f = 0; f < res; f++) {
      cout << ans1[f] << " " << ans2[f] << endl;
    }
  }
}
