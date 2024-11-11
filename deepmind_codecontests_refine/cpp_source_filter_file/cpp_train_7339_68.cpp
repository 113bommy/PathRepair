#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  char d[8][8] = {0};
  int mna = 1e9 + 42, mnb = 1e9 + 42;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) cin >> d[i][j];
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      if (d[i][j] == 'W') {
        int cur = 0;
        int cx = i;
        while (cx != 0) {
          cur += (d[cx][j] == 'B') * 10;
          cur++;
          cx--;
        }
        cur += (d[cx][j] == 'B') * 10;
        mna = min(mna, cur);
      } else if (d[i][j] == 'B') {
        int cur = 0;
        int cx = i;
        while (cx != 7) {
          cur += (d[cx][j] == 'A') * 10;
          cur++;
          cx++;
        }
        cur += (d[cx][j] == 'A') * 10;
        mnb = min(mnb, cur);
      }
    }
  cout << (mna <= mnb ? 'A' : 'B');
  return 0;
}
