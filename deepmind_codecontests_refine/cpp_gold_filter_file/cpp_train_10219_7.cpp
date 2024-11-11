#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  bool vis[n + 1], flagg[n + 1], flagg1[n + 1];
  memset(vis, false, n + 1);
  memset(flagg, false, n + 1);
  memset(flagg1, false, n + 1);
  int poss;
  if (n <= 2)
    poss = 2 * n - 1;
  else
    poss = 2 * 2 + (n - 2) * 3;
  if (n == 1)
    cout << 0 << endl;
  else {
    for (int i = 1; i <= k; i++) {
      int x;
      cin >> x;
      if (!vis[x]) {
        poss -= 1;
        vis[x] = true;
        if (vis[x + 1] == true && x + 1 <= n) {
          poss -= 1;
          flagg1[x] = true;
        }
        if (vis[x - 1] == true && x - 1 >= 1) {
          poss -= 1;
          flagg[x] = true;
        }
      } else {
        if (vis[x + 1] == true && x + 1 <= n && flagg1[x] == false) {
          poss -= 1;
          flagg1[x] = true;
        }
        if (vis[x - 1] == true && x - 1 >= 1 && flagg[x] == false) {
          poss -= 1;
          flagg[x] = true;
        }
      }
    }
    cout << poss << endl;
  }
}
