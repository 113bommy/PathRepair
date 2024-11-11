#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, t;
int x[200010];
int y[200010];
vector<pair<int, int> > P[255];
vector<int> pmax[255];
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  cin >> t;
  n = s.size();
  m = t.size();
  int a = 0, b = 0;
  for (int i = (0); i < (200010); i++) {
    x[i] = 10000000;
    y[i] = -10000000;
  }
  for (int i = (m); i < (200010); i++) {
    y[i] = 10000000;
  }
  while ((b < m) and (a < n)) {
    if (s[a] == t[b]) {
      x[b] = a;
      b++;
    }
    a++;
  }
  a = n - 1;
  b = m - 1;
  while ((b >= 0) and (a >= 0)) {
    if (s[a] == t[b]) {
      y[b] = a;
      b--;
    }
    a--;
  }
  for (int i = (0); i < (m); i++) {
    P[t[i]].push_back(make_pair((i - 1) < 0 ? -10000000 : x[i - 1], y[i + 1]));
  }
  for (int i = ('a'); i <= ('z'); i++) {
    if (P[i].size() == 0) continue;
    sort(P[i].begin(), P[i].end());
    pmax[i] = *new vector<int>(P[i].size());
    pmax[i][0] = P[i][0].second;
    for (int j = (1); j < (P[i].size()); j++) {
      pmax[i][j] = (((pmax[i][j - 1]) > (P[i][j].second)) ? (pmax[i][j - 1])
                                                          : (P[i][j].second));
    }
  }
  for (int j = (0); j < (n); j++) {
    int X = s[j];
    if (P[X].size() == 0) {
      cout << "No" << endl;
      ;
      return 0;
    }
    if (P[X][0].first >= j) {
      cout << "No" << endl;
      ;
      return 0;
    }
    int l = 0, r = P[X].size() - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (P[X][mid].first >= j) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    if (pmax[X][l] <= j) {
      cout << "No" << endl;
      ;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
