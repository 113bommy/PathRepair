#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void solve(std::istream& in, std::ostream& out) {
    vector<string> g1, g2;
    string s;
    int n1, m1, n2, m2;
    in >> n1 >> m1;
    for (int i = 1; i <= n1; i++) {
      in >> s;
      g1.push_back(s);
    }
    in >> n2 >> m2;
    for (int i = 1; i <= n2; i++) {
      in >> s;
      g2.push_back(s);
    }
    int mx = -1;
    int posx, posy;
    for (int x = -50; x <= 50; x++) {
      for (int y = -50; y <= 50; y++) {
        int sum = 0;
        for (int i = 0; i <= n1 - 1; i++) {
          for (int j = 0; j <= m1 - 1; j++) {
            int ix = i + x;
            int jy = j + y;
            if (ix < n2 && ix >= 0 && jy < m2 && jy >= 0) {
              int a = g1[i][j] - '0';
              int b = g2[ix][jy] = '0';
              sum += (a * b);
            }
          }
        }
        if (sum >= mx) {
          mx = sum;
          posx = x;
          posy = y;
        }
      }
    }
    out << posx << ' ' << posy << endl;
  }
};
void solve(std::istream& in, std::ostream& out) {
  out << fixed << std::setprecision(6);
  Solution solution;
  solution.solve(in, out);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  istream& in = cin;
  ostream& out = cout;
  solve(in, out);
  return 0;
}
