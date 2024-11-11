#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
vector<int> v[30];
int main() {
  string s;
  cin >> s;
  int sz = (int)(s).size(), n;
  n = sz;
  for (int i = 0; i < (sz); i++) {
    v[s[i] - 'a'].push_back(i + 1);
  }
  int mn = 100005 * 10, mx, pre, d;
  for (int i = 0; i < (26); i++) {
    sz = v[i].size();
    pre = 0;
    if (sz) {
      mx = 0;
      for (int j = 0; j < (sz); j++) {
        d = v[i][j] - pre;
        pre = v[i][j];
        mx = max(mx, d);
      }
      d = n + 1 - pre;
      mx = max(d, mx);
      mn = min(mn, mx);
    }
  }
  cout << mn << endl;
  return 0;
}
