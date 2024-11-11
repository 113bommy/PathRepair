#include <bits/stdc++.h>
using namespace std;
int mem[10002][4][8][8], n, mod = 1000000007;
string j[10];
string p[10];
int f(int su, int sa, int a, int b) {
  if (mem[su][sa][a][b] != -1) return mem[su][sa][a][b];
  if (su == n) return 1;
  if (sa >= 3) return f(su + 1, 0, b, 0);
  if (j[sa][su] == 'X' || (a & (1 << sa))) return f(su, sa + 1, a, b);
  int res = 0;
  int t = 1 << sa;
  if (j[sa][su] != 'X' && j[sa][su + 1] != 'X' && !(t & a))
    res += f(su, sa + 1, (a | (1 << sa)), b | (1 << sa));
  if (j[sa][su] != 'X' && j[sa + 1][su] != 'X' && !(a & 3 << sa))
    res += f(su, sa + 1, (a | (1 << sa) | (1 << (sa + 1))), b);
  return mem[su][sa][a][b] = res % mod;
}
int b(int a, int x, int y, char ch) {
  if (a == 1) {
    if (x - 2 >= 0) {
      if (j[y][x - 2] != ch && j[y][x - 1] != ch) {
        j[y][x - 2] = j[y][x - 1] = ch;
        return 1;
      } else
        return 0;
    } else {
      return 0;
    }
  } else if (a == 2) {
    if (x + 2 < n) {
      if (j[y][x + 2] != ch && j[y][x + 1] != ch) {
        j[y][x + 2] = j[y][x + 1] = ch;
        return 1;
      } else
        return 0;
    } else
      return 0;
  } else if (a == 3) {
    if (y - 2 >= 0) {
      if (j[y - 2][x] != ch && j[y - 1][x] != ch) {
        j[y - 1][x] = j[y - 2][x] = ch;
        return 1;
      } else
        return 0;
    } else
      return 0;
  } else if (a == 4) {
    if (y + 2 < 3) {
      if (j[y + 2][x] != ch && j[y + 1][x] != ch) {
        j[y + 1][x] = j[y + 2][x] = ch;
        return 1;
      } else
        return 0;
    } else
      return 0;
  }
}
int cnt(int a) {
  int res = 0;
  for (int i = 0; i < 4; i++) res += (a & (1 << i)) > 0;
  return res;
}
int main() {
  cin >> n;
  int xo = 0, yo = 0, javab = 0;
  for (int i = 0; i < 3; i++) {
    cin >> j[i];
    if (j[i].find("O") != string::npos) {
      xo = j[i].find("O");
      yo = i;
    }
    j[i] += 'X';
  }
  j[yo][xo] = 'X';
  j[3] = string(n + 1, 'X');
  for (int i = 0; i < 4; i++) p[i] = j[i];
  for (int i = 1; i < 16; i++) {
    int k = i;
    int bb = 1;
    for (int t = 1; t <= 4; t++, k /= 2)
      if (k & 1) bb *= b((k & 1) * t, xo, yo, 'X');
    if (bb) {
      memset(mem, -1, sizeof mem);
      if (cnt(i) & 1) {
        javab += f(0, 0, 0, 0);
        javab %= mod;
      } else {
        javab -= f(0, 0, 0, 0) - mod;
        javab %= mod;
      }
    }
    for (int l = 0; l < 4; l++) j[l] = p[l];
  }
  cout << javab << endl;
  int r;
  cin >> r;
}
