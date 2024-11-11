#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int, int>>;
char grid[64][64];
int main() {
  int t;
  for (scanf("%d", &t); t; t--) {
    int r, c;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) scanf("%s", grid[i]);
    bool one = false, two = false, edge = false, corner = false, line = false,
         border = false;
    for (int i = 0; i < r; i++) {
      bool tmp = true;
      for (int j = 0; j < c; j++) {
        if (grid[i][j] == 'A') {
          one = true;
          if ((i == 0 && j == 0) || (i == 0 && j == c - 1) ||
              (i == r - 1 && j == 0) || (i == r - 1 && j == c - 1))
            corner = true;
          else if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
            edge = true;
        } else {
          tmp = false;
          two = true;
        }
      }
      if (tmp) {
        line = true;
        if (i == 0 || i == r - 1) border = true;
      }
    }
    for (int j = 0; j < c; j++) {
      bool tmp = true;
      for (int i = 0; i < r; i++) {
        if (grid[i][j] == 'P') tmp = false;
      }
      if (tmp) {
        line = true;
        if (j == 0 || j == c - 1) border = true;
      }
    }
    if (!one) {
      puts("MORTAL");
      continue;
    }
    int ans = 4;
    if (!two)
      ans = 0;
    else if (border)
      ans = 1;
    else if (corner || line)
      ans = 2;
    else if (edge)
      ans = 3;
    printf("%d\n", ans);
  }
}
