#include <bits/stdc++.h>
using namespace std;
int w, h, t;
set<int> x, y;
set<int>::iterator it;
multiset<int> xx, yy;
multiset<int>::iterator it1, it2;
char op;
int num;
int main() {
  while (scanf("%d%d%d", &w, &h, &t) != -1) {
    x.clear();
    y.clear();
    xx.clear();
    yy.clear();
    x.insert(0);
    x.insert(w);
    y.insert(0);
    y.insert(h);
    xx.insert(w);
    yy.insert(h);
    while (t--) {
      scanf(" %c%d", &op, &num);
      if (op == 'H') {
        it = y.upper_bound(num);
        int pos2 = *(it);
        int pos1 = *(--it);
        y.insert(num);
        yy.insert(pos2 - num);
        yy.insert(num - pos1);
        yy.erase(yy.find(pos2 - pos1));
      } else {
        it = x.upper_bound(num);
        int pos2 = *(it);
        int pos1 = *(--it);
        x.insert(num);
        xx.insert(pos2 - num);
        xx.insert(num - pos1);
        xx.erase(xx.find(pos2 - pos1));
      }
      it1 = xx.end();
      long long ansx = *(--it1);
      it2 = yy.end();
      long long ansy = *(--it2);
      printf("%I64d\n", ansx * ansy);
    }
  }
  return 0;
}
