#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    int n, e;
    set<int> v;
    map<int, int> m;
    cin >> n;
    for (long long int i = 0; i < n; i++) {
      cin >> e;
      m[e]++;
      if (m[e] == 1) v.insert(e);
    }
    int np = 0, ps = 0;
    while (!v.empty()) {
      ps = 0;
      for (map<int, int>::iterator itm = m.begin(); itm != m.end(); itm++) {
        while (itm->second != 0 && itm->first >= ps) {
          itm->second -= 1;
          ps += 1;
        }
        if (itm->second == 0) v.erase(itm->first);
      }
      np++;
    }
    cout << np;
  }
  return 0;
}
