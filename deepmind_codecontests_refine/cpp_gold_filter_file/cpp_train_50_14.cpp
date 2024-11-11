#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int ok = 0;
  vector<int> v;
  set<int> s;
  set<int>::iterator k;
  int x, y;
  while (n--) {
    cin >> y;
    while (y--) {
      cin >> x;
      v.push_back(x);
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    s.insert(v[i]);
  }
  int i = 1;
  if (s.size() < m) {
    cout << "NO" << endl;
    return 0;
  }
  for (k = s.begin(); k != s.end(); k++) {
    if (*k != i) {
      ok = 1;
      break;
    }
    i++;
  }
  if (ok == 1) cout << "NO" << endl;
  if (ok == 0) cout << "YES" << endl;
  return 0;
}
