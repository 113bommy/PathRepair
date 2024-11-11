#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int MAXI = 0x7fffffff;
int in() {
  int x = 0, c;
  for (; (unsigned)((c = getchar()) - '0') >= 10;) {
    if (c == '-') return -in();
    if (!~c) throw ~0;
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while ((unsigned)((c = getchar()) - '0') < 10);
  return x;
}
int main(int argc, char *argv[]) {
  long col, row, k;
  cin >> row >> col >> k;
  int r[row], c[col], a[row][col];
  for (int i = (0), _b = (row); i < _b; i++)
    for (int j = (0), _b = (col); j < _b; j++) cin >> a[i][j];
  for (int i = (0), _b = (row); i < _b; i++) r[i] = i;
  for (int i = (0), _b = (col); i < _b; i++) c[i] = i;
  for (int i = (0), _b = (k); i < _b; i++) {
    char s;
    int x, y;
    cin >> s >> x >> y;
    if (s == 'g') cout << a[r[x - 1]][c[y - 1]] << endl;
    if (s == 'r') swap(r[x - 1], r[y - 1]);
    if (s == 'c') swap(c[x - 1], c[y - 1]);
  }
  return 0;
}
