#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> m >> n;
  vector<vector<long long> > v(m);
  for (int i = 0; i < m; i++) {
    v[i].resize(n);
    for (int j = 0; j < n; j++) cin >> v[i][j];
  }
  vector<int> win;
  for (int i = 0; i < m; i++) {
    long long mx = 0;
    for (int j = 0; j < n; j++) mx = max(mx, v[i][j]);
    for (int j = 0; j < n; j++)
      if (v[i][j] == mx) {
        win.push_back(j + 1);
        break;
      }
  }
  int arr[101];
  fill(arr, arr + 101, 0);
  for (int i = 0; i < win.size(); i++) arr[win[i]]++;
  int mx = 0, winindex;
  for (int i = 100; i >= 0; i--)
    if (arr[i] >= mx) mx = arr[i], winindex = i;
  cout << winindex;
}
