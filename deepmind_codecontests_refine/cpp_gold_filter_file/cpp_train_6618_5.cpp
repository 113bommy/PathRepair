#include <bits/stdc++.h>
using namespace std;
vector<pair<int, string> > res;
map<string, int> m;
map<string, int> m1;
int n;
string mn;
bool cmp(pair<int, string> x, pair<int, string> y) {
  if (x.first == y.first) return x.second > y.second;
  return x.first < y.first;
}
int main() {
  cin >> mn >> n;
  m["posted"] = 15;
  m["commented"] = 10;
  m["likes"] = 5;
  for (int i = 0; i < n; i++) {
    string x, y, a, f, l;
    cin >> x >> a;
    if (a == "posted" || a == "commented") cin >> f;
    cin >> y >> f;
    l = y.substr(0, (int)y.size() - 2);
    if (x != mn && l != mn) m1[x] += 0, m1[l] += 0;
    if (x == mn) m1[l] += m[a];
    if (l == mn) m1[x] += m[a];
  }
  for (map<string, int>::iterator it = m1.begin(); it != m1.end(); it++)
    res.push_back(make_pair(it->second, it->first));
  sort(res.begin(), res.end(), cmp);
  for (int i = (int)res.size() - 1; i >= 0; i--) cout << res[i].second << "\n";
  return 0;
}
