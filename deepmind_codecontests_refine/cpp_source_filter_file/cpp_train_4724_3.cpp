#include <bits/stdc++.h>
using namespace std;
const int MAX = INT_MAX;
const double EPS = 1e-10;
const double PI = 2 * asin(1.0);
const long long mod = 1e9 + 7;
inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
int main() {
  string s;
  cin >> s;
  map<int, pair<int, int> > mapa;
  int eu = 0;
  for (int i = 0; i < ((int)s.size()); ++i) {
    if (i == 0) {
      mapa[eu].first = -1;
      mapa[eu].second = -1;
    } else {
      if (s[i - 1] == 'l') {
        if (mapa[eu].second == -1) {
          mapa[i].second = -1;
          mapa[i].first = eu;
          mapa[eu].second = i;
        } else {
          mapa[i].first = eu;
          mapa[i].second = mapa[eu].second;
          mapa[mapa[eu].second].first = i;
          mapa[eu].second = i;
        }
      } else {
        if (mapa[eu].first == -1) {
          mapa[eu].first = i;
          mapa[i].second = eu;
          mapa[i].first = -1;
        } else {
          mapa[i].second = eu;
          mapa[i].first = mapa[eu].first;
          mapa[mapa[eu].first].second = i;
          mapa[eu].first = i;
        }
      }
    }
    eu = i;
  }
  int pos;
  map<int, pair<int, int> >::iterator it = mapa.begin();
  while (it != mapa.end()) {
    if (it->second.second == -1) {
      pos = it->first;
      break;
    }
    it++;
  }
  while (pos != -1) {
    printf("%d\n", pos);
    pos = mapa[pos].first;
  }
}
