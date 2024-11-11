#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846264338327950288419716939937511;
const double eps = 1e-9;
char ch_ch_ch[1 << 20];
inline string gs() {
  scanf("%s", ch_ch_ch);
  return string(ch_ch_ch);
}
inline string gl() {
  gets(ch_ch_ch);
  return string(ch_ch_ch);
}
inline int gi() {
  int x;
  scanf("%d", &x);
  return x;
}
const int inf = 1000000000;
int n;
vector<string> a;
signed char dp[21][1 << 20];
char was[21][1 << 20];
int newmask(int diag, int mask, char c) {
  int res = 0;
  if (diag < n)
    for (int x = diag, y = 0; x >= 0; --x, ++y) {
      if (mask & (1 << x)) {
        if (x + 1 < n && a[x + 1][y] == c) res |= (1 << (x + 1));
        if (y + 1 < n && a[x][y + 1] == c) res |= (1 << (x));
      }
    }
  else
    for (int x = n - 1, y = diag - n + 1; y < n; --x, ++y) {
      if (mask & (1 << x)) {
        if (x + 1 < n && a[x + 1][y] == c) res |= (1 << (x + 1));
        if (y + 1 < n && a[x][y + 1] == c) res |= (1 << (x));
      }
    }
  return res;
}
signed char R(int diag, int mask) {
  if (was[diag][mask]) return dp[diag][mask];
  was[diag][mask] = 1;
  signed char& r = dp[diag][mask];
  if (diag == 2 * n - 2) return r = 0;
  if (diag & 1) {
    r = -100;
    for (char c = 'a'; c <= 'z'; ++c) {
      int nmask = newmask(diag, mask, c);
      if (nmask) r = max((int)r, (c == 'a') - (c == 'b') + R(diag + 1, nmask));
    }
  } else {
    r = 100;
    for (char c = 'a'; c <= 'z'; ++c) {
      int nmask = newmask(diag, mask, c);
      if (nmask) r = min((int)r, (c == 'a') - (c == 'b') + R(diag + 1, nmask));
    }
  }
  return r;
}
void solution() {
  n = gi();
  a.resize(n);
  for (int i = 0; i < (n); ++i) a[i] = gs();
  memset(dp, -1, sizeof(dp));
  signed char res = (a[0][0] == 'a') - (a[0][0] == 'b') + R(0, 1);
  if (res > 0) printf("FIRST");
  if (res < 0) printf("SECOND");
  if (res == 0) printf("DRAW");
  cout << endl;
}
int main(int argc, char** argv) {
  solution();
  return 0;
}
