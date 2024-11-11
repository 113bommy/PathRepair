#include <bits/stdc++.h>
using namespace std;
bool pr(int s, int a, int b) {
  cout << "2 " << s << " " << a << " " << b << "\n";
  cout.flush();
  int v;
  cin >> v;
  if (v == 1)
    return true;
  else
    return false;
}
int fsq(int a, int b, int c) {
  cout << "1 " << a << " " << b << " " << c << "\n";
  cout.flush();
  int v;
  cin >> v;
  return v;
}
int main() {
  int n;
  cin >> n;
  int right = 2, last = 0, v;
  for (int i = (3); i != (n + 1); i++)
    if (pr(1, i, right)) right = i;
  vector<double> sq(n + 1, 0);
  double m = 0;
  for (int i = 2; i <= n; i++)
    if (i != right) {
      cout << "1 " << 1 << " " << right << " " << i << "\n";
      cout.flush();
      cin >> sq[i];
    }
  for (int i = 0; i <= n; i++)
    if (m < sq[i]) {
      m = sq[i];
      last = i;
    }
  set<pair<double, int>> l, r;
  for (int i = 0; i != (n + 1); i++)
    if (sq[i] && i != last)
      pr(1, last, i) ? l.insert({sq[i], i}) : r.insert({sq[i], i});
  vector<int> ans;
  ans.push_back(1), ans.push_back(right);
  for (auto it : r) ans.push_back(it.second);
  ans.push_back(last);
  vector<int> vsp;
  for (auto it : l) vsp.push_back(it.second);
  for (int i = vsp.size() - 1; i != -1; i--) ans.push_back(vsp[i]);
  cout << "0 ";
  for (auto it : ans) cout << it << " ";
  return 0;
}
