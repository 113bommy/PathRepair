#include <bits/stdc++.h>
using namespace std;
int ask(set<int> i) {
  cout << "? " << i.size();
  for (int j : i) cout << ' ' << j;
  cout << endl;
  int ans;
  cin >> ans;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v[k];
    for (int i = 0; i < k; ++i) {
      int c;
      cin >> c;
      v[i].resize(c);
      for (int j = 0; j < c; ++j) cin >> v[i][j];
    }
    set<int> all;
    for (int i = 1; i <= n; ++i) all.insert(i);
    int l = 0, r = k, mx = ask(all);
    while (l < r - 1) {
      set<int> s(all);
      int mid = l + r >> 1;
      for (int i = l; i < mid; ++i)
        for (int j : v[i]) s.erase(j);
      if (ask(s) == mx)
        l = mid;
      else
        r = mid;
    }
    for (int i : v[l]) all.erase(i);
    int tmp = ask(all);
    cout << '!';
    for (int i = 0; i < k; ++i) cout << ' ' << (i == l ? tmp : mx);
    cout << endl;
    string is;
    cin >> is;
    if (is[0] == 'I') exit(0);
  }
}
