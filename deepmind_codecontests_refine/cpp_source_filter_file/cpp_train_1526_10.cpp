#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, i;
  scanf("%d%d%d", &n, &a, &b);
  int x = log2(n);
  if (pow(2, x) != n) x++;
  set<int> s;
  set<int>::iterator it;
  for (i = 1; i <= n; i++) s.insert(i);
  for (i = 1; i <= x; i++) {
    for (it = s.begin(); it != s.end();) {
      int r1, r2;
      r1 = *it;
      it++;
      r2 = *it;
      it++;
      if (r1 == a && r2 == b || r1 == b && r2 == a) {
        if (i != x)
          printf("%d\n", i);
        else
          printf("Final\n");
        return 0;
      }
      if (r1 == a || r1 == b)
        s.erase(r2);
      else
        s.erase(r1);
    }
  }
  return 0;
}
