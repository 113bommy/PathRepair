#include <bits/stdc++.h>
using namespace std;
int n, m, k, inp, ans, k1;
vector<pair<int, int>> sor;
map<int, int> p;
void sort1() {
  sor.clear();
  for (map<int, int>::iterator x = p.begin(); x != p.end(); x++)
    sor.push_back(make_pair(x->second, x->first));
  p.clear();
  sort(sor.begin(), sor.end());
  for (int i = 0; i < sor.size(); i++) p[sor[i].first] = sor[i].second;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> inp;
    p[i] = inp;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> inp;
      map<int, int>::iterator k;
      for (map<int, int>::iterator u = p.begin(); u != p.end(); u++)
        if (u->second == inp) {
          ans += (u->first) + 1;
          k = u;
          break;
        }
      int y = 1;
      for (map<int, int>::iterator lol = p.begin(); lol != p.end(); lol++) {
        if (k != lol) {
          sor.push_back(make_pair(y, lol->second));
          y++;
        } else
          sor.push_back(make_pair(1, lol->second));
      }
      p.clear();
      for (int i = 0; i < sor.size(); i++) p[sor[i].first] = sor[i].second;
      sor.clear();
    }
  }
  cout << ans;
  return 0;
}
