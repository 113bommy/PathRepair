#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int inf = 2e9 + 5;
double PI = 3.14159265358979323846;
void solve() {
  int q, r, b, n, p;
  q = 9;
  r = 5;
  b = 3;
  n = 3;
  p = 1;
  string s[8];
  for (int i = 0; i < 8; i++) {
    cin >> s[i];
  }
  int black, white;
  black = 0;
  white = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      char c = s[i][j];
      if (c == 'q') black += q;
      if (c == 'r') black += r;
      if (c == 'b') black += b;
      if (c == 'n') black += n;
      if (c == 'p') black += p;
      if (c == 'Q') white += q;
      if (c == 'R') white += r;
      if (c == 'B') white += b;
      if (c == 'N') white += n;
      if (c == 'P') white += p;
    }
  }
  if (black < white)
    cout << "White";
  else if (white < black)
    cout << "Black";
  else
    cout << "Draw";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
