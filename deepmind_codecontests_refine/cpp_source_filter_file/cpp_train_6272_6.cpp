#include <bits/stdc++.h>
using namespace std;
int query(int x, int y) {
  int c = y - x + 1, ans;
  cout << "? " << c;
  for (int i = x; i <= y; i++) cout << " " << i;
  cout << endl;
  cin >> ans;
  return ans;
}
int bs(int l, int r, int ma) {
  while (l <= r) {
    if (l == r) return l;
    int m = (l + r) / 2;
    int w = query(l, m);
    if (w == ma)
      r = m;
    else
      l = m + 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> s[k + 1];
    int c, x;
    for (int i = 1; i <= k; i++) {
      cin >> c;
      for (int j = 0; j < c; j++) {
        cin >> x;
        s[i].push_back(x);
      }
    }
    int ma = query(1, n);
    int p = bs(1, n, ma);
    vector<int> ans;
    for (int i = 1; i <= k; i++) {
      int f = 0;
      for (int j = 0; j < s[i].size(); j++) {
        if (s[i][j] == p) {
          f = 1;
          break;
        }
      }
      if (f == 0)
        ans.push_back(p);
      else {
        int ne;
        set<int> g;
        for (int j = 0; j < s[i].size(); j++) g.insert(s[i][j]);
        cout << "? " << n - s[i].size();
        for (int i = 1; i <= n; i++)
          if (g.count(i) == 0) cout << " " << i;
        cout << endl;
        cin >> ne;
        ans.push_back(ne);
      }
    }
    string ck;
    cout << "! ";
    for (int i = 0; i < ans.size(); i++) cout << " " << ans[i];
    cout << endl;
    cin >> ck;
  }
  return 0;
}
