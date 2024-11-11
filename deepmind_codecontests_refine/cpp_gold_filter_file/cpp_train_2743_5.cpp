#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, c[N], deg[N], cdeg[N], ki, ai;
vector<int> G[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= n; ++i) {
    cin >> ki;
    for (int j = 1; j <= ki; ++j) {
      cin >> ai;
      G[ai].push_back(i);
      deg[i]++;
    }
  }
  int r = 1 << 20;
  for (int s = 1; s <= 3; ++s) {
    memcpy(cdeg, deg, sizeof deg);
    int cs = s, m = 0, cr = 0;
    while (1) {
      while (1) {
        bool found = false;
        for (int i = 1; i <= n; ++i) {
          if (cdeg[i] == 0 && c[i] == cs) {
            cr++;
            m++;
            for (int j : G[i]) cdeg[j]--;
            cdeg[i]--;
            found = true;
            break;
          }
        }
        if (!found) break;
      }
      if (m < n) {
        cs = cs % 3 + 1;
        cr++;
      } else
        break;
    }
    r = min(r, cr);
  }
  cout << r << endl;
}
