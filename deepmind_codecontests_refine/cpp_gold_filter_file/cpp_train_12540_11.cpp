#include <bits/stdc++.h>
using namespace std;
int DP[2001][2000];
string s, p;
int togl[2001];
int fine[2001];
int main(void) {
  cin >> s >> p;
  for (int i = 0; i < s.size(); i++) {
    togl[i] = INT_MAX / 2;
    fine[i] = i;
    int iter = 0, k = 0;
    while (1) {
      if (k == p.size()) {
        togl[i] = iter - k;
        fine[i] = i + iter - 1;
        break;
      }
      if (i + iter == s.size()) break;
      if (p[k] != s[i + iter])
        iter++;
      else
        k++, iter++;
    }
  }
  for (int n = 1; n < 2000; n++) {
    set<int> alb;
    alb.insert(INT_MAX / 2);
    DP[s.size()][n] = INT_MAX / 2;
    for (int inizio = s.size() - 1; inizio >= 0; inizio--) {
      alb.insert(togl[inizio] + DP[fine[inizio] + 1][n - 1]);
      DP[inizio][n] = *alb.begin();
    }
    alb.clear();
  }
  for (int x = 0; x <= s.size(); x++) {
    int da = 0, a = 2000;
    while (1) {
      if (da == a) break;
      int quanti = (da + a + 1) / 2;
      int almeno = DP[0][quanti];
      int rem = s.size() - quanti * p.size() - almeno;
      if (almeno <= x && rem >= (x - almeno))
        da = quanti;
      else
        a = quanti - 1;
    }
    cout << da << " ";
  }
}
