#include <bits/stdc++.h>
using namespace std;
int main() {
  int ttt, i, j, m, n, d, flag, c, k, q, x;
  vector<int> v(150004);
  vector<int> bul(150004, 0);
  set<pair<int, int> > s;
  scanf("%d%d%d", &n, &k, &q);
  for (i = 0; i <= n - 1; i++) {
    scanf("%d", &d);
    v[i + 1] = d;
  }
  while (q--) {
    scanf("%d%d", &x, &d);
    if (x == 1) {
      s.insert(make_pair(-v[d], d));
      bul[d] = 1;
    } else {
      if (bul[d] == 0)
        printf("No\n");
      else {
        set<pair<int, int> >::iterator it = s.begin();
        i = 0;
        while (1) {
          if (it == s.end() || i == k) {
            printf("No\n");
            break;
          }
          if ((*it).second == d) {
            printf("Yes\n");
            break;
          }
          i++;
          it++;
        }
      }
    }
  }
  return 0;
}
