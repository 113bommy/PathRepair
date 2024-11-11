#include <bits/stdc++.h>
using namespace std;
struct P {
  P(int x, int y, int id) : x(x), y(y), id(id) {}
  int x, y, id;
  bool operator<(const P& p) const {
    if (x == p.x) return y < p.y;
    return x < p.x;
  }
};
vector<P> mgTab[1005];
int main() {
  int n, x, y;
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) {
    scanf("%d%d", &x, &y);
    mgTab[y / 1000].push_back(P(x, y, i + 1));
  }
  for (int i = 0; i <= 1000; ++i) sort(mgTab[i].begin(), mgTab[i].end());
  for (int i = 0; i <= 1000; ++i) {
    if (i % 2 == 0) {
      for (int j = 0; j < mgTab[i].size(); ++j) {
        printf("%d ", mgTab[i][j].id);
      }
    } else {
      for (int j = mgTab[i].size() - 1; j >= 0; --j) {
        printf("%d ", mgTab[i][j].id);
      }
    }
  }
  printf("\n");
  return 0;
}
