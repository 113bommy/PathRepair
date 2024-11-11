#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  vector<int> l[26];
  for (int i = 0; i < s.size(); i++) {
    l[s[i] - 'a'].push_back(i);
  }
  int n = s.size() - 1;
  int min1 = INT_MAX;
  for (int i = 0; i < 26; i++) {
    int max1 = -1;
    int p = 0;
    for (int j = 0; j < l[i].size(); j++) {
      if (j == 0) {
        max1 = max(max1, l[i][j] + 1);
      } else {
        max1 = max(max1, l[i][j] - p);
      }
      p = l[i][j];
    }
    if (p != n - 1 && l[i].size() > 0) {
      max1 = max(max1, n - 1 - p + 1);
    }
    if (l[i].size() > 0) min1 = min(min1, max1);
  }
  cout << min1;
}
