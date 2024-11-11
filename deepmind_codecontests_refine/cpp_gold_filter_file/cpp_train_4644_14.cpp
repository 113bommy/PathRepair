#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while ((c < '0' || c > '9') && c - '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return x * f;
}
const int N = 1e5 + 10;
int n, rot;
struct pig {
  int ch[2];
  int siz;
} q[N << 5];
int x, y, cnt = 0;
void jia(int &t, int zhi, int pan, int wz) {
  if (!t) t = ++cnt;
  q[t].siz += pan;
  if (wz == -1) return;
  int g = (zhi >> wz) & 1;
  jia(q[t].ch[g], zhi, pan, wz - 1);
}
int typ, dan = 0;
void cha(int t, int x, int lim, int wz) {
  if (wz == -1) return;
  int g1 = (x >> wz) & 1, g2 = (lim >> wz) & 1;
  if (g2) dan += q[q[t].ch[g1]].siz;
  cha(q[t].ch[g2 ^ g1], x, lim, wz - 1);
}
int main() {
  n = read();
  while (n--) {
    typ = read();
    x = read();
    if (typ == 1) jia(rot, x, 1, 30);
    if (typ == 2) jia(rot, x, -1, 30);
    if (typ == 3) {
      y = read();
      dan = 0;
      cha(rot, x, y, 30);
      cout << dan << "\n";
    }
  }
}
