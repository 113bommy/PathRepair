#include <bits/stdc++.h>
using namespace std;
int main() {
  int L, b, f;
  scanf("%i %i %i\n", &L, &b, &f);
  vector<int> zauzet(L + b + f);
  set<pair<int, pair<int, int> > > automobili;
  int n;
  scanf("%i", &n);
  for (int i = 0; i < n; i++) {
    int t, d;
    scanf("%i %i", &t, &d);
    if (t == 1) {
      int s = d + b + f;
      int tr = b;
      bool nasao = false;
      for (int j = 0; j < zauzet.size(); j++) {
        if (!zauzet[j])
          tr++;
        else
          tr = 0;
        if (tr == s) {
          tr = j - f;
          automobili.insert({i, {tr, tr - d + 1}});
          for (int kk = 0; kk < d; kk++) {
            zauzet[tr] = 1;
            tr--;
          }
          printf("%i\n", tr + 1);
          nasao = true;
          break;
        }
      }
      if (!nasao) printf("-1\n");
    } else {
      d--;
      pair<int, pair<int, int> > p = *automobili.lower_bound({d, {0, 0}});
      assert(d == p.first);
      automobili.erase(p);
      for (int j = p.second.second; j <= p.second.first; j++) {
        zauzet[j] = 0;
      }
    }
  }
  return 0;
}
