#include <bits/stdc++.h>
using namespace std;
long long a[3];
int main() {
  int n;
  set<int> a[30], b[30];
  cin >> n;
  char c;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c != '?') {
      a[c - 'a'].insert(i + 1);
    } else {
      a[28].insert(i + 1);
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c != '?') {
      b[c - 'a'].insert(i + 1);
    } else {
      b[28].insert(i + 1);
    }
  }
  int x = 0, rs = 0;
  vector<pair<int, int>> r;
  for (int i = 0; i < 27; i++) {
    x = a[i].size() - b[i].size();
    x = max(a[i].size(), b[i].size()) - abs(x);
    if (x) {
      rs += x;
      while (x--) {
        r.push_back({*a[i].begin(), *b[i].begin()});
        a[i].erase(a[i].begin());
        b[i].erase(b[i].begin());
      }
    }
  }
  for (int i = 0; i < 27; i++) {
    x = min(a[i].size(), b[28].size());
    if (x) {
      rs += x;
      while (x--) {
        r.push_back({*a[i].begin(), *b[28].begin()});
        a[i].erase(a[i].begin());
        b[28].erase(b[28].begin());
      }
    }
  }
  for (int i = 0; i < 27; i++) {
    x = min(b[i].size(), a[28].size());
    if (x) {
      rs += x;
      while (x--) {
        r.push_back({*b[i].begin(), *a[28].begin()});
        b[i].erase(b[i].begin());
        a[28].erase(a[28].begin());
      }
    }
  }
  x = min(b[28].size(), a[28].size());
  if (x) {
    rs += x;
    while (x--) {
      r.push_back({*b[28].begin(), *a[28].begin()});
      b[28].erase(b[28].begin());
      a[28].erase(a[28].begin());
    }
  }
  cout << rs << "\n";
  for (auto c : r) {
    cout << c.first << ' ' << c.second << "\n";
  }
  return 0;
}
