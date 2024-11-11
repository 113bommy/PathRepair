#include <bits/stdc++.h>
using namespace std;
int H, W;
int A[303][303];
int B[303][303];
int R[303], C[303];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> H >> W;
  for (y = 0; y < (H); y++) {
    for (x = 0; x < (W); x++) {
      cin >> r;
      R[y] = max(R[y], r);
      C[x] = max(C[x], r);
    }
  }
  int CH = 0, CW = 0;
  queue<pair<int, int>> Q;
  for (i = H * W; i >= 1; i--) {
    int inR = count(R, R + H, i);
    int inC = count(C, C + W, i);
    if (inR) CH++;
    if (inC) CW++;
    if (inR || inC) {
      B[CH - 1][CW - 1] = i;
    } else {
      y = Q.front().first;
      x = Q.front().second;
      B[y][x] = i;
      Q.pop();
    }
    if (inR) {
      for (x = CW - 2; x >= 0; x--) Q.push({CH - 1, x});
    }
    if (inC) {
      for (y = CH - 2; y >= 0; y--) Q.push({y, CW - 1});
    }
  }
  for (y = 0; y < (H); y++) {
    for (x = 0; x < (W); x++) cout << B[y][x] << " ";
    cout << endl;
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
