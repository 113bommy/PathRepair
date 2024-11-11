#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n);
  for (auto& i : v) {
    cin >> i;
  }
  vector<int> s(n);
  for (auto& i : s) {
    cin >> i;
  }
  set<int> q;
  for (int i = 0; i < k; i++) {
    int t;
    cin >> t;
    q.insert(v[t - 1]);
  }
  vector<vector<int>> school(m + 1);
  for (int i = 0; i < n; i++) {
    school[s[i]].push_back(v[i]);
  }
  int need = 0;
  for (int i = 0; i <= m; i++) {
    sort(school[i].rbegin(), school[i].rend());
    for (int j = 0; j < school[i].size(); j++) {
      if (q.count(school[i][j]) && j > 0) need++;
    }
  }
  cout << need << endl;
}
