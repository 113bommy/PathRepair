#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1000000;
const int Tmax = 1000000000;
map<int, int> ult;
map<int, int> aib[Nmax + 1];
void upd(int k, int t, int x) {
  while (t <= Tmax) {
    aib[k][t] += x;
    t += (t & -t);
  }
}
int qry(int k, int t) {
  int ans = 0;
  while (t >= 1) {
    ans += aib[k][t];
    t -= (t & -t);
  }
  return ans;
}
int main() {
  int n, dist = 0;
  cin >> n;
  while (n--) {
    int a, t, x;
    cin >> a >> t >> x;
    if (a == 1) {
      if (ult[x] == 0) {
        dist++;
        ult[x] = dist;
        aib[dist].clear();
      }
      upd(ult[x], t, 1);
    } else if (a == 2) {
      upd(ult[x], t, -1);
    } else {
      cout << qry(ult[x], t) << "\n";
    }
  }
  return 0;
}
