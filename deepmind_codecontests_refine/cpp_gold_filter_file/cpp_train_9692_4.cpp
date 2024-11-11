#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second - a.first > b.second - b.first)
    return true;
  else
    return false;
}
int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int count = 0;
  int r, c = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'B') {
        count++;
        r = i;
        if (c == -1) c = j;
      }
    }
    if (count) break;
  }
  cout << r + (count / 2) + 1 << " " << c + (count / 2) + 1 << endl;
  return 0;
}
