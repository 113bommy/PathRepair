#include <bits/stdc++.h>
using namespace std;
int n, m, nr, fl[55], fc[55];
char a[55][55];
int dl[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
void ve(int l, int c) {
  fl[l] = nr;
  fc[c] = nr;
  a[l][c] = 'x';
  for (int i = 1; i < l; i++)
    if (a[i][c] == '#') ve(i, c);
  for (int i = l + 1; i <= n; i++)
    if (a[i][c] == '#') ve(i, c);
  for (int j = 1; j < c; j++)
    if (a[l][j] == '#') ve(l, j);
  for (int j = c + 1; j <= m; j++)
    if (a[l][j] == '#') ve(l, j);
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i <= n; i++) cin.getline(a[i] + 1, 55);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == '#') {
        nr++;
        ve(i, j);
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == '.' && fl[i] == fc[i] && fl[i]) {
        cout << "No";
        return 0;
      }
  cout << "Yes";
}
