#include <bits/stdc++.h>
using namespace std;
int dr[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dc[] = {1, -1, 0, 0, -1, 1, -1, 1};
long long mod = 1e9 + 7;
const int MAX = 1e5 + 7;
struct ch {
  int x, y, z;
  ch() {
    x = 0;
    y = 0;
    z = 0;
  }
};
ch sum[MAX];
int main() {
  string s;
  cin >> s;
  for (long long i = 0; i < s.length(); ++i) {
    sum[i].x = (s[i] == 'x'), sum[i].y = (s[i] == 'y'),
    sum[i].z = (s[i] == 'z');
    if (i) {
      sum[i].x += sum[i - 1].x, sum[i].y += sum[i - 1].y,
          sum[i].z += sum[i - 1].z;
    }
  }
  int q;
  cin >> q;
  for (long long i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    int x = sum[b].x - sum[a].x + (s[a] == 'x');
    int y = sum[b].y - sum[a].y + (s[a] == 'y');
    int z = sum[b].z - sum[a].z + (s[a] == 'z');
    int l = b - a + 1;
    if (l < 2)
      cout << "YES\n";
    else if (l % 3 == 0)
      if ((x == y && y == z))
        cout << "YES\n";
      else
        cout << "NO\n";
    else if (l % 3 == 1)
      if ((x == y && x == z - 1) || (x == z && x == y - 1) ||
          (y == z && z == x - 1))
        cout << "YES\n";
      else
        cout << "NO\n";
    else if (l % 3 == 2)
      if ((x == y && x == z + 1) || (x == z && x == y + 1) ||
          (y == z && z == x + 1))
        cout << "YES\n";
      else
        cout << "NO\n";
  }
}
