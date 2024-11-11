#include <bits/stdc++.h>
using namespace std;
vector<pair<string, int> > res;
bool find(vector<pair<string, int> > a, string b) {
  for (int i = 0; i < a.size(); i++)
    if (a[i].first == b) {
      return true;
    }
  return false;
}
int main() {
  double k;
  int m, n, level;
  string name;
  cin >> m >> n >> k;
  double kk = k * 100 + 1e-8;
  for (int i = 0; i < m; i++) {
    cin >> name >> level;
    if (level * kk >= 10000) res.push_back(pair<string, int>(name, level * kk));
  }
  for (int i = 0; i < n; i++) {
    cin >> name;
    if (!find(res, name)) res.push_back(pair<string, int>(name, 0));
  }
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++)
    cout << res[i].first << ' ' << res[i].second / 100 << endl;
  return 0;
}
