#include <bits/stdc++.h>
using namespace std;
long long int numdigit(long long int n) { return floor(log10(n)) + 1; }
bool isPowerTwo(long long int x) { return x && (!(x & (x - 1))); }
char v[101][101];
int a, b, c, d, n;
void print() {
  for (int i = 0; i < max(b, d); i++) {
    for (int j = 0; j < a + c; j++) cout << v[i][j];
    cout << "\n";
  }
}
vector<int> fill(int x, int y, int dr, int nm, char c) {
  while (nm) {
    if (v[x][y] == '#') {
      v[x][y] = c;
      nm--;
    }
    if (dr == 1)
      y++;
    else
      y--;
    if (y == a + c) {
      x++;
      dr = -1;
      y = a + c - 1;
    }
    if (y == -1) {
      x++;
      dr = 1;
      y = 0;
    }
  }
  return {x, y, dr};
}
int main() {
  int t = 1, x = 0;
  while (t--) {
    cin >> a >> b >> c >> d >> n;
    int ar[n];
    for (auto &x : ar) cin >> x;
    int mn = min(b, d);
    for (int i = 0; i < max(b, d); i++) {
      for (int j = 0; j < a + c; j++) {
        if (min(b, d) == d) {
          if (i >= min(b, d) && j >= a)
            v[i][j] = '.';
          else
            v[i][j] = '#';
        } else {
          if (i >= min(b, d) && j < a)
            v[i][j] = '.';
          else
            v[i][j] = '#';
        }
      }
    }
    vector<int> it = {0, 0, 1};
    if (max(b, d) == b) {
      if (min(b, d) % 2 != 0) it = {0, a + c - 1, -1};
    } else {
      if (min(b, d) % 2 != 0)
        it = {0, 0, 1};
      else
        it = {0, a + c - 1, -1};
    }
    for (int i = 0; i < n; i++) {
      it = fill(it[0], it[1], it[2], ar[i], (i + 'a'));
    }
    cout << "YES\n";
    print();
  }
  return 0;
}
