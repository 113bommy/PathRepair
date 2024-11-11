#include <bits/stdc++.h>
const double pi = 3.1415926535897;
using namespace std;
int kx[] = {-1, 1, -1, 1, 2, 2, -2, -2};
int ky[] = {-2, -2, 2, 2, -1, 1, -1, 1};
int mark[8][8] = {};
int main() {
  string r, k;
  cin >> r >> k;
  int tot = 64;
  int rx = r[0] - 97;
  int ry = stoi(r.substr(1)) - 1;
  int kxp = k[0] - 97;
  int kyp = stoi(k.substr(1)) - 1;
  for (int i = 0; i < 8; i++) {
    int nx = kxp + kx[i];
    int ny = kyp + ky[i];
    if (nx < 8 && nx >= 0 && ny < 8 && ny >= 0) {
      if (nx != rx && ny != ry) tot--, mark[nx][ny] = 1;
    }
  }
  for (int i = 0; i < 8; i++) {
    int nx = rx + kx[i];
    int ny = ry + ky[i];
    if (nx < 8 && nx >= 0 && ny < 8 && ny >= 0) {
      if (nx == kxp && ny == kyp) continue;
      if (!mark[nx][ny]) tot--;
    }
  }
  cout << tot - 16;
}
