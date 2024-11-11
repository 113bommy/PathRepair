#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> v;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
  }
  std::vector<string>::iterator it;
  int x1 = m, x2 = -1, y1 = m, y2 = -1;
  for (int i = 0; i < n; i++) {
    s = v[i];
    for (int j = 0; j < m; j++) {
      if (s[j] == 'X') {
        x1 = min(x1, j);
        x2 = max(x2, j);
        y1 = min(y1, i);
        y2 = max(y2, i);
      }
    }
  }
  for (int i = y1; i <= y2; i++) {
    s = v[i];
    for (int j = x1; j <= x2; j++) {
      if (s[j] == '.') {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}
