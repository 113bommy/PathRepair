#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n, 0);
  vector<int> q(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }
  set<int> vals1;
  set<int> vals2;
  vector<int> rights;
  for (int i = 0; i < n; i++) {
    if (vals2.count(p[i])) {
      vals2.erase(p[i]);
    } else {
      vals1.insert(p[i]);
    }
    if (vals1.count(q[i])) {
      vals1.erase(q[i]);
    } else {
      vals2.insert(q[i]);
    }
    if (vals1.empty() && vals2.empty()) {
      rights.push_back(i);
    }
  }
  if (rights.size() < k) {
    cout << "NO" << endl;
  } else {
    string s(n, ' ');
    int l = 0;
    for (int it = 0; it < rights.size(); it++) {
      int r = rights[it];
      char c = 'a' + min(it, 25);
      for (int i = l; i <= r; i++) {
        s[p[i] - 1] = c;
      }
      l = r + 1;
    }
    cout << "YES" << endl << s << endl;
  }
  return 0;
}
