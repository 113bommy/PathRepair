#include <bits/stdc++.h>
using namespace std;
map<int, int> m2;
set<pair<int, int> > m;
int n;
int ans[111111][3], len;
bool add() {
  set<pair<int, int> >::iterator it1 = m.begin(), it2, it3;
  if (it1 == m.end()) return false;
  it2 = it1;
  it2++;
  if (it2 == m.end()) return false;
  it3 = it2;
  it3++;
  if (it3 == m.end()) return false;
  ans[len][0] = it1->second, ans[len][1] = it2->second,
  ans[len][2] = it3->second;
  len++;
  pair<int, int> t = *it1;
  m.erase(it1);
  t.first++;
  if (t.first) m.insert(t);
  t = *it2;
  m.erase(it2);
  t.first++;
  if (t.first) m.insert(t);
  t = *it3;
  m.erase(it3);
  t.first++;
  if (t.first) m.insert(t);
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    m2[x]++;
  }
  for (map<int, int>::iterator it = m2.begin(); it != m2.end(); it++) {
    m.insert(make_pair(-it->second, it->first));
  }
  while (add())
    ;
  cout << len << '\n';
  for (int i = 0; i < len; i++) {
    int t[3] = {ans[i][0], ans[i][1], ans[i][2]};
    sort(t, t + 3);
    reverse(t, t + 3);
    cout << t[0] << ' ' << t[1] << ' ' << t[2] << '\n';
  }
  return 0;
}
