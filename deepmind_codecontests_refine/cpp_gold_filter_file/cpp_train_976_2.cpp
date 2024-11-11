#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:268435456")
int main() {
  int n;
  cin >> n;
  int mp[201][201];
  for (int i = 0; i < 200; i++)
    for (int j = 0; j < 200; j++) mp[i][j] = 0;
  mp[0][0] = n;
  bool ch = 0;
  do {
    ch = 0;
    for (int i = 0; i < 150; i++)
      for (int j = 0; j < 150; j++) {
        if (mp[i][j] >= 4) {
          mp[i + 1][j] += mp[i][j] / 4;
          mp[i][j + 1] += mp[i][j] / 4;
          if (i != 0) mp[i - 1][j] += mp[i][j] / 4;
          if (j != 0) mp[i][j - 1] += mp[i][j] / 4;
          if (i == 1) mp[i - 1][j] += mp[i][j] / 4;
          if (j == 1) mp[i][j - 1] += mp[i][j] / 4;
          ch = 1;
          mp[i][j] %= 4;
        }
      }
  } while (ch);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    if ((abs(a) > 150) || (abs(b) > 150))
      cout << 0 << endl;
    else
      cout << mp[abs(a)][abs(b)] << endl;
  }
  return 0;
}
