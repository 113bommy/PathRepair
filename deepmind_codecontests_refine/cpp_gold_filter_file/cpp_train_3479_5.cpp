#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 9;
int a[mx];
map<int, int> mp;
stack<int> s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, it = -1, sz = 0;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    mp[a[i]]++;
    it = max(it, a[i]);
    if (mp[a[i]] <= 2) sz++;
  }
  if (mp[it] > 1) sz--;
  cout << sz << endl;
  for (map<int, int>::iterator pt = mp.begin(); pt != mp.end(); pt++) {
    if (pt->second > 1 || pt->first == it) cout << pt->first << " ";
    if (pt->first != it) s.push(pt->first);
  }
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  return 0;
}
