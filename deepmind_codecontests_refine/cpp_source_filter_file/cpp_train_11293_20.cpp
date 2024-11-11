#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const int MAXN = 1000005;
const int MOD = 1e9 + 7;
const int MOD1 = 1e9 + 35011;
const int MOD2 = 1e9 + 18169;
const int INF = (1 << 30);
const long long INFl = 1e18;
int w, h;
char mas[105][105];
int main() {
  scanf("%d %d\n", &w, &h);
  for (size_t i = 0; i < h; ++i) {
    for (size_t j = 0; j < w; ++j) {
      scanf("%c", &mas[w - j - 1][i]);
    }
    char tmp;
    scanf("%c", &tmp);
  }
  swap(w, h);
  for (size_t i = 0; i < w >> 1; ++i) {
    for (size_t j = 0; j < h >> 1; ++j) {
      swap(mas[j][i], mas[h - j - 1][i]);
    }
  }
  for (size_t i = 0; i < h; ++i) {
    string a;
    for (size_t j = 0; j < w; ++j) {
      a.push_back(mas[i][j]);
      a.push_back(mas[i][j]);
    }
    cout << a << '\n' << a << '\n';
  }
  return 0;
}
