#include <bits/stdc++.h>
using namespace std;
struct ac {
  int x, y, z;
} p[3000];
int mo[3000];
vector<pair<int, int> > pr;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
  }
  for (int i = 1; i <= n; ++i) {
    int d = 1e9, f = 0;
    if (mo[i] == 1) continue;
    for (int j = 1; j <= n; ++j) {
      if (mo[j] == 1 || i == j) continue;
      int td =
          abs(p[i].x - p[j].x) + abs(p[j].y - p[i].y) + abs(p[j].z - p[i].z);
      if (td < d) {
        f = j;
        d = td;
      }
    }
    mo[i] = mo[f] = 1;
    cout << i << " " << f << endl;
  }
  return 0;
}
