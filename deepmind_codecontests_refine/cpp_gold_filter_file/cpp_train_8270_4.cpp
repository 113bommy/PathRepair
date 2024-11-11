#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300100;
const int MOD = 1000000000 + 7;
int n, r, g, how_many[MAXN];
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> r >> g;
  int h = 0, nvMax, cur = 0, rez = 0;
  for (int i = 1; (h + i) <= r + g; ++i) {
    h += i;
    nvMax = i;
  }
  how_many[0] = 1;
  for (int i = 1; i <= nvMax && i <= r; ++i) {
    for (int j = r - i; j >= 0; --j) add(how_many[j + i], how_many[j]);
  }
  for (int i = 0; i <= r && i <= h; ++i) {
    if (h - i <= g) add(rez, how_many[i]);
  }
  cout << rez;
  return 0;
}
