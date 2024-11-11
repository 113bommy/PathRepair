#include <bits/stdc++.h>
using namespace std;
struct obj {
  int x, y, ind;
  obj(int x, int y, int ind) : x(x), y(y), ind(ind) {}
  obj() {}
};
int main() {
  vector<obj> s;
  int n, x, y;
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) {
    scanf("%d%d", &x, &y);
    s.push_back(obj(x, y, i));
  }
  sort(s.begin(), s.end(), [](obj a, obj b) {
    if (a.x / 1000 == b.x / 1000) {
      if (a.x / 1000 % 2 == 0)
        return a.y < b.y;
      else
        return a.y < b.y;
    }
    return a.x / 1000 < b.x / 1000;
  });
  for (auto v : s) printf("%d ", v.ind);
  return 0;
}
