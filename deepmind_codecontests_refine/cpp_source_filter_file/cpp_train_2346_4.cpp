#include <bits/stdc++.h>
using namespace std;
int main() {
  string name;
  long long st, reg, id, sc;
  cin >> st >> reg;
  vector<pair<int, string> > v[10005];
  while (st--) {
    cin >> name >> id >> sc;
    v[id].push_back(make_pair(sc, name));
  }
  for (long long i = 1; i <= reg; i++) {
    sort(v[i].begin(), v[i].end());
    reverse(v[i].begin(), v[i].end());
    if (v[i].size() >= 2 && v[i][2].first == v[i][1].first) {
      cout << "?" << endl;
    } else {
      cout << v[i][0].second << " " << v[i][1].second << endl;
    }
  }
}
