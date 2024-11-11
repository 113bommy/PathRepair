#include <bits/stdc++.h>
using namespace std;
void showlist(list<int> g) {
  list<int>::iterator it;
  for (it = g.begin(); it != g.end(); ++it) cout << *it << endl;
  cout << '\n';
}
int main() {
  vector<pair<int, int>> ab;
  vector<pair<int, int>> cd;
  vector<pair<int, int>> anss;
  int p, q, l, r;
  cin >> p >> q >> l >> r;
  int k, m;
  for (int i = 0; i < p; i += 1) {
    cin >> k >> m;
    ab.push_back(make_pair(k, m));
  }
  for (int i = 0; i < q; i += 1) {
    cin >> k >> m;
    cd.push_back(make_pair(k, m));
  }
  for (int a = l; a < r + 1; a += 1) {
    anss.push_back(make_pair(0, a));
  }
  list<int> ans;
  for (unsigned int j = 0; j < ab.size(); j += 1) {
    for (unsigned int i = 0; i < cd.size(); i += 1) {
      for (int a = l; a < r + 1; a += 1) {
        if ((cd[i].second + a >= ab[j].second &&
             cd[i].first + a <= ab[j].second) ||
            (cd[i].second + a <= ab[j].second &&
             cd[i].second + a >= ab[j].first)) {
          if (anss[a].first != 1) anss[a - l].first = 1;
        }
      }
    }
  }
  int result = 0;
  for (int a = l; a < r + 1; a += 1) {
    if (anss[a].first == 1) {
      result += 1;
    }
  }
  cout << result << endl;
  return 0;
}
