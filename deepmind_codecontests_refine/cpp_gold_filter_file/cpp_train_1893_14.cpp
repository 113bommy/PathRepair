#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (t--) {
    long long int start = 0, end = 0, n, m, x = 0, y = 0, index = 0;
    cin >> n;
    long long int arr[n + 1][n + 1];
    for (long int i = 1; i <= n; i++) {
      for (long int j = 1; j <= n; j++) {
        char ch;
        cin >> ch;
        if (ch == '1')
          arr[i][j] = 1;
        else
          arr[i][j] = INT_MAX;
      }
      arr[i][i] = 0;
    }
    for (long int i = 1; i <= n; i++) {
      for (long int j = 1; j <= n; j++) {
        for (long int k = 1; k <= n; k++) {
          arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
        }
      }
    }
    vector<long long int> v;
    cin >> m;
    for (long int i = 0; i < m; i++) {
      cin >> start;
      v.push_back(start);
    }
    vector<long long int> ans;
    ans.push_back(v[0]);
    start = 0;
    for (int i = 1; i < m; i++) {
      if (arr[ans.back()][v[i]] < i - start) {
        start = i - 1;
        ans.push_back(v[i - 1]);
      }
    }
    ans.push_back(v[m - 1]);
    cout << ans.size() << '\n';
    for (auto it : ans) cout << it << " ";
  }
}
