#include <bits/stdc++.h>
using namespace std;
bool Less(const pair<pair<int, int>, pair<int, int>>& s1,
          const pair<pair<int, int>, pair<int, int>>& s2) {
  if (s1.first.first == s2.first.first)
    return s1.first.second > s2.first.second;
  return s1.first.first < s2.first.first;
}
vector<string> da(2100);
vector<int> st(2100);
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> da[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (da[i][j] == '1') st[j]++;
    }
  for (int i = 0; i < n; i++) {
    auto tmp = st;
    for (int j = 0; j < m; j++)
      if (da[i][j] == '1') tmp[j] -= 1;
    int f = 0;
    for (int j = 0; j < m; j++)
      if (tmp[j] % 2 == 0) f = 1;
    if (f == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
