#include <bits/stdc++.h>
using namespace std;
int a[51][51];
int b[51][51];
int main() {
  int na, ma, nb, mb;
  cin >> na >> ma;
  for (int i = 0; i < (int)na; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < (int)na; j++) a[i][j] = s[j] - '0';
  }
  cin >> nb >> mb;
  for (int i = 0; i < (int)nb; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < (int)nb; j++) b[i][j] = s[j] - '0';
  }
  int bestx = -1, besty = -1, best = 0;
  for (int x = -50; x <= 50; x++)
    for (int y = -50; y <= 50; y++) {
      int temp = 0;
      for (int i = 0; i < (int)na; i++)
        for (int j = 0; j < (int)ma; j++) {
          if (i + x >= nb || i + x < 0) continue;
          if (j + y >= mb || j + y < 0) continue;
          temp += a[i][j] * b[i + x][j + y];
        }
      if (temp > best) {
        temp = best;
        bestx = x;
        besty = y;
      }
    }
  cout << bestx << " " << besty << endl;
  return 0;
}
