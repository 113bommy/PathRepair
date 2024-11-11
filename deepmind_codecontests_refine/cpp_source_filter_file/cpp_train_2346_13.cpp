#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<string, int> par[10000][3];
  for (int i = 0; i < 10000; i++)
    par[i][0].second = par[i][1].second = par[i][2].second = 0;
  int n, m;
  cin >> n >> m;
  string name;
  int region, point;
  for (int i = 0; i < n; i++) {
    cin >> name >> region >> point;
    region--;
    if (point > par[region][0].second) {
      par[region][2] = par[region][1];
      par[region][1] = par[region][0];
      par[region][0].first = name;
      par[region][0].second = point;
    } else if (point > par[region][1].second) {
      par[region][2] = par[region][1];
      par[region][1].first = name;
      par[region][1].second = point;
    } else if (point > par[region][2].second) {
      par[region][2].first = name;
      par[region][2].second = point;
    }
  }
  for (int i = 0; i < m; i++) {
    if (par[i][1].second == par[i][2].second)
      cout << "?\n";
    else {
      cout << par[i][0].first << " " << par[i][1].first << endl;
    }
  }
  return 0;
}
