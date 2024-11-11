#include <bits/stdc++.h>
long long const mod = 1e14 + 7;
long long const INFll = 1e18;
int const INF = 2e9;
double const eps = 1e-7;
using namespace std;
char im1[105][105], im2[105][105];
int main() {
  if (0) {
    if (1) {
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    } else {
      freopen("evacuation.in", "r", stdin);
      freopen("evacuation.out", "w", stdout);
    }
  }
  int w, h;
  cin >> w >> h;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> im1[i][j];
    }
  }
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      im2[i][j] = im1[j][i];
    }
  }
  for (int i = 0; i < w; i++) {
    for (int a = 0; a < 2; a++) {
      for (int j = 0; j < h; j++) {
        cout << im2[i][j] << im2[i][j];
      }
      cout << '\n';
    }
  }
}
