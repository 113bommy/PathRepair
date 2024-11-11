#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int f[40][20][10];
  int dom[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  memset(f, 0, sizeof(f));
  int maxi = 0, ansd, ansm, ansy;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i + 2] != '-' || s[i + 5] != '-') continue;
    bool strip = true;
    for (int j = 0; j < 9; ++j) {
      if (j != 2 && j != 5 && s[i + j] == '-') strip = false;
    }
    if (!strip) continue;
    if (s[i + 6] != '2' || s[i + 7] != '0' || s[i + 8] != '1') continue;
    int d = (s[i] - '0') * 10 + s[i + 1] - '0';
    int m = (s[i + 3] - '0') * 10 + s[i + 4] - '0';
    int y = s[i + 9] - '0';
    if (y < 1 || y > 3) continue;
    if (m < 1 || m > 12) continue;
    if (d < 1 || d > dom[m - 1]) continue;
    ++f[d][m][y];
    if (maxi < f[d][m][y]) {
      maxi = f[d][m][y];
      ansd = d;
      ansm = m;
      ansy = y;
    }
  }
  cout << ansd / 10 << ansd % 10 << '-' << ansm / 10 << ansm % 10 << '-'
       << "201" << ansy << endl;
  return 0;
}
