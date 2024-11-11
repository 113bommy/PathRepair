#include <bits/stdc++.h>
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
using namespace std;
void file() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  file();
  int x, y, z;
  cin >> x >> y >> z;
  if (min(x, y) < max(x, y) && max(x, y) == y)
    cout << "-" << '\n';
  else if (min(x, y) < max(x, y) && max(x, y) == x)
    cout << "+" << '\n';
  else if (min(x, y) + z >= max(x, y) && z)
    cout << "?" << '\n';
  else
    cout << "0" << '\n';
}
