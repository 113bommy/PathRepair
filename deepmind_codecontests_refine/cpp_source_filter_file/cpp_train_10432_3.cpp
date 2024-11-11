#include <bits/stdc++.h>
using namespace std;
template <class T, class IT>
inline void PRINT(IT i1, IT i2) {
  cout << '[';
  copy(i1, i2, ostream_iterator<T>(cout, ", "));
  cout << "]\n";
}
int n;
char field[2020][2020];
bool uxcmd[2020], uycmd[2020], bxcmd[2020], bycmd[2020];
int main() {
  for (int i = 0; i < (int)(2020); ++i)
    for (int j = 0; j < (int)(2020); ++j) field[i][j] = '0';
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) cin >> &field[i + 1][1];
  int count = 0;
  fill_n(&uxcmd[0], n + 2, false);
  fill_n(&uycmd[0], n + 2, false);
  for (int x = 1; x < n; ++x) {
    for (int y = n; y > x; --y) {
      if ((field[x][y] == '1') ^ (uxcmd[x] ^ uycmd[y])) {
        ++count;
        uxcmd[x] = !uxcmd[x];
        uycmd[y] = !uycmd[y];
      }
    }
  }
  fill_n(&bxcmd[0], n + 2, false);
  fill_n(&bycmd[0], n + 2, false);
  for (int x = n; x > 1; --x) {
    for (int y = 1; y < x; ++y) {
      if ((field[x][y] == '1') ^ (bxcmd[x] ^ bycmd[y])) {
        ++count;
        bxcmd[x] = !bxcmd[x];
        bycmd[y] = !bycmd[y];
      }
    }
  }
  for (int x = (int)(1); x < (int)(n); ++x) {
    if ((field[x][x] == '1') ^ (bxcmd[x] ^ bycmd[x] ^ uxcmd[x] ^ uycmd[x])) {
      ++count;
    }
  }
  cout << count << endl;
  return 0;
}
