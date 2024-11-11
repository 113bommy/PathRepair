#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    map<int, int> s;
    map<int, int> s1;
    vector<vector<int>> aa;
    vector<vector<int>> aa1;
    vector<int> d(n + m + 1);
    for (int i = 0; i < n; i++) {
      vector<int> a(m);
      for (int j = 0; j < m; j++) {
        cin >> a[j];
      }
      aa.push_back(a);
      s[a[0]] = i;
      d[a[0] - 1]++;
    }
    for (int i = 0; i < m; i++) {
      vector<int> a1(n);
      for (int j = 0; j < n; j++) {
        cin >> a1[j];
      }
      aa1.push_back(a1);
      s1[a1[0]] = i;
      d[a1[0] - 1]++;
    }
    int y;
    for (int i = 0; i < n + m + 1; i++) {
      if (d[i] == 2) {
        y = s1[i + 1];
        break;
      }
    }
    for (auto i : aa1[y]) {
      for (auto j : aa[s[i]]) {
        cout << j << " ";
      }
      cout << "\n";
    }
  }
}
