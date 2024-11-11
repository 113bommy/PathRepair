#include <bits/stdc++.h>
using namespace std;
string graphe[100];
int main() {
  int n, m;
  char color_pres;
  cin >> n >> m >> color_pres;
  for (int c = 0; c < n; c++) cin >> graphe[c];
  map<char, bool> deja_vus;
  deja_vus[color_pres] = true;
  deja_vus['.'] = true;
  int total = 0;
  for (int c = 0; c < n; c++)
    for (int c2 = 0; c2 < m; c2++)
      if (deja_vus[graphe[c][c2]] == true)
        continue;
      else {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for (int c3 = 0; c3 < 4; c3++) {
          int x2 = c + dx[c3];
          int y2 = c2 + dy[c3];
          if (x2 >= 0 && y2 >= 0 && x2 < n && y2 < m &&
              graphe[x2][y2] == color_pres) {
            total++;
            deja_vus[graphe[c][c2]] = true;
            break;
          }
        }
      }
  cout << total;
}
