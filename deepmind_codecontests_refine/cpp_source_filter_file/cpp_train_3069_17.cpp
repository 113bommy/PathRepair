#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
}
int a[1000006];
int b[1000006];
int c[1000006];
int main() {
  fastIO();
  int n;
  int m;
  int cnt = 0;
  int p, q, r;
  int cntr = 0;
  int v = 0;
  int check = 0;
  int x, y, z;
  string s[10], s1, s2;
  for (int i = 0; i < 8; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (s[i][j] == 'q') {
        cntr += 9;
      }
      if (s[i][j] == 'r') {
        cntr += 5;
      }
      if (s[i][j] == 'b') {
        cntr += 3;
      }
      if (s[i][j] == 'k') {
        cntr += 3;
      }
      if (s[i][j] == 'p') {
        cntr += 1;
      }
      if (s[i][j] == 'Q') {
        cnt += 9;
      }
      if (s[i][j] == 'R') {
        cnt += 5;
      }
      if (s[i][j] == 'B') {
        cnt += 3;
      }
      if (s[i][j] == 'K') {
        cnt += 3;
      }
      if (s[i][j] == 'P') {
        cnt += 1;
      }
    }
  }
  if (cnt > cntr) cout << "White" << endl;
  if (cnt < cntr) cout << "Black" << endl;
  if (cnt == cntr) cout << "Draw" << endl;
  return 0;
}
