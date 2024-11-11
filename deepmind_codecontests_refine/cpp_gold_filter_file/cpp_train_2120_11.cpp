#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, m1, n2, m2;
  cin >> n1 >> m1;
  string s1[n1];
  for (int i = 0; i < n1; i++) cin >> s1[i];
  cin >> n2 >> m2;
  string s2[n2];
  for (int i = 0; i < n2; i++) cin >> s2[i];
  int mx = 0, xx, yy;
  for (int x = -max(n2, n1); x < max(n1, n2); x++) {
    for (int y = -max(m2, m1); y < max(m1, m2); y++) {
      int s = 0;
      for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
          if (x + i < n2 && x + i >= 0 && y + j >= 0 && y + j < m2 &&
              s1[i][j] == '1' && s2[i + x][j + y] == '1')
            s++;
        }
      }
      if (s >= mx) mx = s, xx = x, yy = y;
    }
  }
  cout << xx << " " << yy << endl;
  return 0;
}
