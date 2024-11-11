#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  vector<pair<int, int> > da, db;
  for (int i = (1); i < (a); i++) {
    int j = sqrt(a * a - i * i);
    for (int t = (-1); t < (2); t++) {
      if ((j + t) * (j + t) + i * i == a * a) {
        if (j + t > 0 && j + t < a) {
          da.push_back(make_pair(j + t, i));
          da.push_back(make_pair(i, j + t));
        }
      }
    }
  }
  for (int i = (1); i < (b); i++) {
    int j = sqrt(b * b - i * i);
    for (int t = (-1); t < (2); t++) {
      if ((j + t) * (j + t) + i * i == b * b) {
        if (j + t > 0 && j + t < b) {
          db.push_back(make_pair(j + t, i));
          db.push_back(make_pair(i, j + t));
        }
      }
    }
  }
  bool flaga = false;
  for (int i = (0); i < (da.size()); i++) {
    for (int j = (0); j < (db.size()); j++) {
      int x, y, z, t;
      x = da[i].first;
      y = da[i].second;
      z = db[j].first;
      t = db[j].second;
      if (x * z == y * t && y != t) {
        printf("YES\n");
        printf("%d %d\n%d %d\n%d %d\n", -x, y, 0, 0, z, t);
        return 0;
      }
    }
  }
  printf("NO\n");
  return 0;
}
