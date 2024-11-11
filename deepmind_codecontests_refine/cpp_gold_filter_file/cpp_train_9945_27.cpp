#include <bits/stdc++.h>
using namespace std;
char X[2][3], Y[2][3];
char XX[4], YY[4];
map<int, int> nxt{{0, 2}, {2, 3}, {3, 1}, {1, 0}};
int main() {
  cin >> X[0] >> X[1] >> Y[0] >> Y[1];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      XX[i * 2 + j] = X[i][j];
      YY[i * 2 + j] = Y[i][j];
    }
  }
  int itx = 0, ity = 0;
  while (XX[itx] != 'A') itx = nxt[itx];
  while (YY[ity] != 'A') ity = nxt[ity];
  while (XX[itx] == 'A' || XX[itx] == 'X') itx = nxt[itx];
  while (YY[ity] == 'A' || YY[ity] == 'X') ity = nxt[ity];
  if (XX[itx] == YY[ity])
    cout << "YES";
  else
    cout << "NO";
}
