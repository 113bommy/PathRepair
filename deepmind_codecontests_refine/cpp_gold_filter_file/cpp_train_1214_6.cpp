#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> a, b;
int n, m;
bool can() {
  for (int i = 0; i < n; ++i) {
    int sp = -1;
    for (int j = 0; j < m; ++j) {
      if (a[i].first == b[j].first && a[i].second != b[j].second) {
        if (sp == -1)
          sp = a[i].first;
        else if (a[i].first != sp)
          sp = -2;
      }
      if (a[i].first == b[j].second && a[i].second != b[j].first) {
        if (sp == -1)
          sp = a[i].first;
        else if (a[i].first != sp)
          sp = -2;
      }
      if (a[i].second == b[j].first && a[i].first != b[j].second) {
        if (sp == -1)
          sp = a[i].second;
        else if (a[i].second != sp)
          sp = -2;
      }
      if (a[i].second == b[j].second && a[i].first != b[j].first) {
        if (sp == -1)
          sp = a[i].second;
        else if (a[i].second != sp)
          sp = -2;
      }
    }
    if (sp == -2) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  a.resize(12);
  b.resize(12);
  for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
  for (int i = 0; i < m; ++i) cin >> b[i].first >> b[i].second;
  int sp = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i].first == b[j].first && a[i].second != b[j].second) {
        if (sp == -1)
          sp = a[i].first;
        else if (a[i].first != sp)
          sp = -2;
      }
      if (a[i].first == b[j].second && a[i].second != b[j].first) {
        if (sp == -1)
          sp = a[i].first;
        else if (a[i].first != sp)
          sp = -2;
      }
      if (a[i].second == b[j].first && a[i].first != b[j].second) {
        if (sp == -1)
          sp = a[i].second;
        else if (a[i].second != sp)
          sp = -2;
      }
      if (a[i].second == b[j].second && a[i].first != b[j].first) {
        if (sp == -1)
          sp = a[i].second;
        else if (a[i].second != sp)
          sp = -2;
      }
    }
  }
  if (sp >= 0) {
    cout << sp;
    return 0;
  }
  if (can()) {
    swap(a, b);
    swap(n, m);
    if (can()) {
      cout << 0;
      return 0;
    }
  }
  cout << -1;
}
