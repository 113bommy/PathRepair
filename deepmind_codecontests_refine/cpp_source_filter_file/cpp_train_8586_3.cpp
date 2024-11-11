#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128000000")
using namespace std;
void solve();
int main() {
  string s = "";
  cin.tie(0);
  cout.sync_with_stdio(0);
  cout.precision(10);
  cout << fixed;
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
int n;
vector<int> a;
vector<vector<int>> table;
vector<int> ans;
void run(vector<int> unused) {
  for (int i = 0; i < unused.size(); ++i) {
    if (a[unused[i]] == 0) {
      ans.push_back(unused[i]);
      for (int j = 0; j < n; ++j) {
        a[j] -= table[j][i];
      }
      unused.erase(unused.begin() + i);
      run(unused);
      return;
    }
  }
}
void solve() {
  cin >> n;
  a.resize(n);
  table.assign(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      table[j][i] = c - '0';
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    b.push_back(i);
  }
  run(b);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] + 1 << " ";
    ;
  }
}
