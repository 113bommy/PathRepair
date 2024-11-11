#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<tuple<int, int, int>, int> > cor;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    cor.push_back(make_pair(make_tuple(x, y, z), i + 1));
  }
  sort(cor.begin(), cor.end());
  vector<pair<tuple<int, int, int>, int> > cor2;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      int x = get<0>(cor[i].first);
      int y = get<1>(cor[i].first);
      int z = get<2>(cor[i].first);
      cor2.push_back(make_pair(make_tuple(y, z, x), cor[i].second));
      break;
    }
    int x = get<0>(cor[i].first);
    int nx = get<0>(cor[i + 1].first);
    int y = get<1>(cor[i].first);
    int ny = get<1>(cor[i + 1].first);
    int z = get<2>(cor[i].first);
    if (x == nx && y == ny) {
      cout << cor[i].second << " " << cor[i + 1].second << endl;
      i++;
    } else {
      cor2.push_back(make_pair(make_tuple(y, z, x), cor[i].second));
    }
  }
  sort(cor2.begin(), cor2.end());
  vector<pair<tuple<int, int, int>, int> > cor3;
  int n2 = cor2.size();
  for (int i = 0; i < cor2.size(); i++) {
    if (i == n2 - 1) {
      int y = get<0>(cor2[i].first);
      int z = get<1>(cor2[i].first);
      int x = get<2>(cor2[i].first);
      cor3.push_back(make_pair(make_tuple(z, x, y), cor2[i].second));
      break;
    }
    int y = get<0>(cor2[i].first);
    int ny = get<0>(cor2[i + 1].first);
    int z = get<1>(cor2[i].first);
    int nz = get<1>(cor2[i + 1].first);
    int x = get<2>(cor2[i].first);
    if (y == ny && z == nz) {
      cout << cor2[i].second << " " << cor2[i + 1].second << endl;
      i++;
    } else {
      cor3.push_back(make_pair(make_tuple(z, x, y), cor2[i].second));
    }
  }
  sort(cor3.begin(), cor3.end());
  vector<pair<tuple<int, int, int>, int> > cor4;
  int n3 = cor3.size();
  for (int i = 0; i < cor3.size(); i++) {
    if (i == n3 - 1) {
      int z = get<0>(cor3[i].first);
      int x = get<1>(cor3[i].first);
      int y = get<2>(cor3[i].first);
      cor4.push_back(make_pair(make_tuple(x, y, z), cor3[i].second));
      break;
    }
    int z = get<0>(cor3[i].first);
    int nz = get<0>(cor3[i + 1].first);
    int x = get<1>(cor3[i].first);
    int nx = get<1>(cor3[i + 1].first);
    int y = get<2>(cor3[i].first);
    if (z == nz && x == nx) {
      cout << cor3[i].second << " " << cor3[i + 1].second << endl;
      i++;
    } else {
      cor4.push_back(make_pair(make_tuple(x, y, z), cor3[i].second));
    }
  }
  sort(cor4.begin(), cor4.end());
  int hojix = -1;
  int n4 = cor4.size();
  for (int i = 0; i < cor4.size(); i++) {
    if (i == n4 - 1) {
      cout << hojix << " " << cor4[i].second << endl;
      break;
    }
    int x = get<0>(cor4[i].first);
    int nx = get<0>(cor4[i + 1].first);
    if (x == nx) {
      cout << cor4[i].second << " " << cor4[i + 1].second << endl;
      i++;
    } else if (hojix > 0) {
      cout << hojix << " " << cor4[i].second << endl;
      hojix = -1;
    } else {
      hojix = cor4[i].second;
    }
  }
  return 0;
}
