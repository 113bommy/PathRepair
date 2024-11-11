#include <bits/stdc++.h>
using namespace std;
int a[10];
map<pair<int, int>, int> res;
map<pair<pair<int, int>, int>, int> sg;
int getsg(int x, int y, int z) {
  if (x == 0 && y == 0 && z == 0) return 0;
  int b[4];
  b[1] = x, b[2] = y, b[3] = z;
  sort(b + 1, b + 4);
  x = b[1], y = b[2], z = b[3];
  if (sg.find(make_pair(make_pair(x, y), z)) != sg.end())
    return sg[make_pair(make_pair(x, y), z)];
  int vis[610];
  memset(vis, false, sizeof(vis));
  for (int i = (1); i < (x + 1); i++) vis[getsg(x - i, y - i, z - i)] = true;
  for (int i = (1); i < (x + 1); i++) vis[getsg((x - i), y, z)] = true;
  for (int i = (1); i < (y + 1); i++) vis[getsg(x, y - i, z)] = true;
  for (int i = (1); i < (z + 1); i++) vis[getsg(x, y, z - i)] = true;
  for (int i = (0); i < (610); i++)
    if (!vis[i]) return sg[make_pair(make_pair(x, y), z)] = i;
}
bool vis[400];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = (1); i < (n + 1); i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  if (n == 1) {
    if (a[1] > 0)
      cout << "BitLGM"
           << "\n";
    else
      cout << "BitAryo"
           << "\n";
  } else if (n == 2) {
    int x = 1, y = 1;
    while (x + y <= 300) {
      while (vis[x]) x++;
      vis[x] = true;
      vis[x + y] = true;
      res[make_pair(x, x + y)] = 1;
      y++;
    }
    if (!res[make_pair(a[1], a[2])])
      cout << "BitLGM"
           << "\n";
    else
      cout << "BitAryo"
           << "\n";
  } else {
    if (!(a[1] ^ a[2] ^ a[3]))
      cout << "BitLGM"
           << "\n";
    else
      cout << "BitAryo"
           << "\n";
  }
  return 0;
}
