#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int i, j, l, x, next[200005] = {0}, vis[200005] = {0};
  vector<int> v1, v;
  cin >> s;
  l = s.length();
  for (i = 0; i < l; i++) {
    next[i] = -1;
    vis[j] = -1;
  }
  for (i = l - 1; i >= 0; i--) {
    if (s[i] == '0') {
      v.push_back(i);
    } else if (s[i] == '1') {
      if (v.size() > 0) {
        x = v.back();
        next[i] = x;
        v.pop_back();
      } else {
        cout << -1;
        return 0;
      }
    }
  }
  for (i = l - 1; i >= 0; i--) {
    if (s[i] == '1') {
      v1.push_back(i);
    } else if (s[i] == '0') {
      if (v1.size() > 0) {
        x = v1.back();
        next[i] = x;
        v1.pop_back();
      }
    }
  }
  if (v1.size() > 0) {
    cout << -1;
    return 0;
  }
  vector<vector<int> > v3;
  for (i = 0; i < l; i++) {
    if (vis[i] != 1) {
      vector<int> v2;
      j = i;
      while (1) {
        vis[j] = 1;
        v2.push_back(j);
        if (next[j] == -1) {
          break;
        }
        j = next[j];
      }
      v3.push_back(v2);
    }
  }
  cout << v3.size() << endl;
  for (i = 0; i < v3.size(); i++) {
    cout << v3[i].size() << " ";
    for (j = 0; j < v3[i].size(); j++) {
      cout << v3[i][j] + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
