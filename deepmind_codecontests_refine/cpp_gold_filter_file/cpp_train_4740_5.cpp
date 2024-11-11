#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 100 * 200 + 2, maxm = 20, SQ = 1000,
          inf = 1000 * 100 * 100 * 100, mod = 1000 * 1000 * 1000 + 7,
          base = 255;
vector<string> v;
int main() {
  for (int a = 0; a <= 9; a++) {
    for (int b = 0; b <= 9; b++) {
      for (int c = 0; c <= 9; c++) {
        for (int d = 0; d <= 9; d++) {
          if (a != b and a != c and a != d and b != c and b != d and c != d) {
            char A = (a + '0');
            char B = (b + '0');
            char C = (c + '0');
            char D = (d + '0');
            string s = "";
            s += A;
            s += B;
            s += C;
            s += D;
            v.push_back(s);
          }
        }
      }
    }
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    vector<string> g;
    for (int j = 0; j < (int)v.size(); j++) {
      int A = 0, B = 0;
      for (int z = 0; z < 4; z++)
        if (v[j][z] == s[z]) A++;
      for (int z = 0; z < 4; z++)
        for (int zz = 0; zz < 4; zz++)
          if (z != zz and v[j][z] == s[zz]) B++;
      if (A == x and B == y) g.push_back(v[j]);
    }
    v.clear();
    for (int j = 0; j < (int)g.size(); j++) v.push_back(g[j]);
  }
  if ((int)v.size() == 0) return cout << "Incorrect data" << endl, 0;
  if ((int)v.size() > 1) return cout << "Need more data" << endl, 0;
  return cout << v[0] << endl, 0;
}
