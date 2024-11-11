#include <bits/stdc++.h>
using namespace std;
struct poz {
  int x, y;
};
poz start[205], finish[205];
int n, m, k, cntsol;
string sol = "";
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> start[i].x >> start[i].y;
  }
  for (int i = 1; i <= k; i++) {
    cin >> finish[i].x >> finish[i].y;
  }
  for (int i = 1; i < m; i++) {
    sol = sol + 'L';
  }
  for (int i = 1; i < n; i++) {
    sol = sol + 'U';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      if (i % 2) {
        sol = sol + 'R';
      } else
        sol = sol + 'L';
    }
    sol = sol + 'D';
  }
  cout << sol.size() << '\n';
  cout << sol;
}
