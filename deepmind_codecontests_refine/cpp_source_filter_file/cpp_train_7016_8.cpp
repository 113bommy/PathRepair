#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
int main() {
  set<int> xx, yy;
  set<pair<int, int> > pp;
  for (int i = 0; i < (8); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    xx.insert(x);
    yy.insert(y);
    if (pp.count(make_pair(x, y))) return 0 * puts("ugly");
    pp.insert(make_pair(x, y));
  }
  if (((int)(xx).size()) != 3 && ((int)(yy).size()) != 3)
    puts("ugly");
  else {
    set<int>::iterator it;
    it = xx.begin();
    it++;
    int v1 = *it;
    it = yy.begin();
    it++;
    int v2 = *it;
    puts(pp.count(make_pair(v1, v2)) ? "ugly" : "respectable");
  }
  return 0;
}
