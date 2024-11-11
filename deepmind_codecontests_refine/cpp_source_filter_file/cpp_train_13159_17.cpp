#include <bits/stdc++.h>
using namespace std;
int c1, c2, c3, c4, n, m;
int rs1, rs2, rs3, rs4, rs;
int a, b;
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cin.tie(0);
  ;
  cin >> c1 >> c2 >> c3 >> c4;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    rs1 += min(a * c1, c2);
  }
  rs2 = min(rs1, c3);
  for (int i = 1; i <= n; i++) {
    cin >> b;
    rs3 += min(b * c1, c2);
  }
  rs4 = min(rs3, c3);
  cout << min(rs2 + rs4, c4);
  return 0;
}
