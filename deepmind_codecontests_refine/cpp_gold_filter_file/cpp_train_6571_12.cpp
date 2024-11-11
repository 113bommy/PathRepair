#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int num = 1e9, mix, miy;
set<pair<int, int> > S;
pair<int, int> p[3];
int getdis(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
  for (int i = 0; i < 3; i++) cin >> p[i].first >> p[i].second;
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MAXN; j++) {
      int tmp = 0;
      for (int k = 0; k < 3; k++) tmp += getdis(p[k], {i, j});
      if (tmp < num) num = tmp, mix = i, miy = j;
    }
  for (int k = 0; k < 3; k++) {
    for (int i = p[k].first; i <= mix; i++) S.insert({i, p[k].second});
    for (int i = p[k].first; i >= mix; i--) S.insert({i, p[k].second});
  }
  for (int k = 0; k < 3; k++) {
    for (int i = p[k].second; i <= miy; i++) S.insert({mix, i});
    for (int i = p[k].second; i >= miy; i--) S.insert({mix, i});
  }
  cout << S.size() << '\n';
  for (set<pair<int, int> >::iterator it = S.begin(); it != S.end(); it++)
    cout << (*it).first << ' ' << (*it).second << '\n';
}
