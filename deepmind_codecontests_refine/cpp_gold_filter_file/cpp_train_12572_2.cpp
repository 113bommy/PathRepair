#include <bits/stdc++.h>
using namespace std;
int kmin(int a = 1 << 31 - 1, int b = 1 << 31 - 1, int c = 1 << 31 - 1,
         int d = 1 << 31 - 1) {
  return min(min(min(a, b), c), d);
}
int pan[4][105];
struct D {
  D(int a = 0, int b = 0, int CC = 0) {
    w = a;
    r = b;
    c = CC;
  }
  int w;
  int r;
  int c;
};
vector<D> v;
int main() {
  int n, k;
  cin >> n >> k;
  int zero = 0;
  for (int c = 0; c < 4; c++)
    for (int i = 0; i < n; i++) {
      cin >> pan[c][i];
      if (!pan[c][i] && (c == 1 || c == 2)) zero++;
    }
  if (zero == 0) {
    for (int i = 0; i < n; i++) {
      if (pan[0][i] == pan[1][i] && pan[1][i]) {
        v.push_back(D(pan[1][i], 1, i + 1));
        pan[1][i] = 0;
        zero = 1;
        break;
      }
      if (pan[2][i] == pan[3][i] && pan[2][i]) {
        v.push_back(D(pan[2][i], 4, i + 1));
        pan[2][i] = 0;
        zero = 1;
        break;
      }
    }
    if (zero == 0) {
      cout << -1;
      return 0;
    }
  }
  int shu = 0;
  int lr = 1;
  int lc = 0;
  while (zero != 2 * n) {
    shu++;
    int r = (shu % (2 * n)) / n + 1;
    int c = shu % (2 * n) % n;
    if (r == 2) c = n - c - 1;
    if (!pan[r][c]) {
    } else if (r == 1 && pan[1][c] == pan[0][c] && pan[1][c]) {
      v.push_back(D(pan[1][c], 1, c + 1));
      pan[1][c] = 0;
      zero++;
    } else if (r == 2 && pan[2][c] == pan[3][c] && pan[2][c]) {
      v.push_back(D(pan[2][c], 4, c + 1));
      pan[2][c] = 0;
      zero++;
    } else if (!pan[lr][lc]) {
      v.push_back(D(pan[r][c], lr + 1, lc + 1));
      pan[lr][lc] = pan[r][c];
      pan[r][c] = 0;
    }
    lr = r;
    lc = c;
  }
  int len = v.size();
  cout << len << endl;
  for (int i = 0; i < v.size(); i++) {
    printf("%d %d %d\n", v[i].w, v[i].r, v[i].c);
  }
  return 0;
}
