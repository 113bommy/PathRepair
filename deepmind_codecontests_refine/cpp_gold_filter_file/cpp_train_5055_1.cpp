#include <bits/stdc++.h>
int pos = 1 << 17;
char buf[1 << 17];
int n, left, right, q, k[2];
long long s[2][200009], val;
struct node {
  long long best, lazy;
} aint[2][265000];
inline char nextch() {
  if (pos == 1 << 17) fread(buf, 1 << 17, 1, stdin), pos = 0;
  return buf[pos++];
}
inline int read() {
  int x = 0;
  char ch = nextch();
  while (!isdigit(ch)) ch = nextch();
  while (isdigit(ch)) {
    x = 10 * x + ch - '0';
    ch = nextch();
  }
  return x;
}
inline void unite(node &n, node st, node dr) {
  n.best = std::min(st.best, dr.best);
}
inline void propag(node &n, node &st, node &dr) {
  st.best += n.lazy;
  st.lazy += n.lazy;
  dr.best += n.lazy;
  dr.lazy += n.lazy;
  n.lazy = 0;
}
void build(int p, int st, int dr) {
  if (st == dr) {
    aint[q][p].best = s[q][st];
    aint[q][p].lazy = 0;
  } else {
    int m = (st + dr) / 2;
    build(2 * p, st, m);
    build(2 * p + 1, m + 1, dr);
    unite(aint[q][p], aint[q][2 * p], aint[q][2 * p + 1]);
  }
}
void update(int p, int st, int dr) {
  if ((left <= st) && (dr <= right)) {
    aint[q][p].best += val;
    aint[q][p].lazy += val;
  } else {
    propag(aint[q][p], aint[q][2 * p], aint[q][2 * p + 1]);
    int m = (st + dr) / 2;
    if (left <= m) update(2 * p, st, m);
    if (m + 1 <= right) update(2 * p + 1, m + 1, dr);
    unite(aint[q][p], aint[q][2 * p], aint[q][2 * p + 1]);
  }
}
void query(int p, int st, int dr) {
  if ((left <= st) && (dr <= right))
    val = std::min(val, aint[q][p].best);
  else {
    propag(aint[q][p], aint[q][2 * p], aint[q][2 * p + 1]);
    int m = (st + dr) / 2;
    if (left <= m) query(2 * p, st, m);
    if (m + 1 <= right) query(2 * p + 1, m + 1, dr);
  }
}
inline void baga(int ind, int x, int y, int z) {
  left = std::max(x, 1);
  right = std::min(y, k[ind]);
  if (left <= right) {
    val = z;
    q = ind;
    update(1, 1, k[q]);
  }
}
inline long long aflu(int ind, int x, int y) {
  left = std::max(x, 1);
  right = std::min(y, k[ind]);
  if (left <= right) {
    q = ind;
    val = 1000000000000000000LL;
    query(1, 1, k[q]);
  } else
    val = 0;
  return val;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++)
    s[i % 2][(i + 1) / 2] = read() - s[1 - i % 2][i / 2];
  k[0] = n / 2;
  k[1] = n - n / 2;
  q = 0;
  build(1, 1, k[0]);
  q = 1;
  build(1, 1, k[1]);
  int m = read();
  for (int i = 0; i < m; i++) {
    int t = read();
    if (t == 1) {
      int x = read() + 1;
      int y = read() + 1;
      int z = read();
      if ((y - x) % 2 == 0) {
        baga(x % 2, (x + 1) / 2, k[x % 2], z);
        baga((y + 1) % 2, y / 2 + 1, k[(y + 1) % 2], -z);
      } else
        baga(x % 2, (x + 1) / 2, y / 2, z);
    } else {
      int x = read() + 1;
      int y = read() + 1;
      int ans = 1;
      long long sum = aflu((x - 1) % 2, x / 2, x / 2);
      long long last = aflu(y % 2, (y + 1) / 2, (y + 1) / 2);
      if ((y - x) % 2 == 0)
        last += sum;
      else
        last -= sum;
      if (last != (y - x + 1) % 2)
        ans = 0;
      else {
        long long cat =
            aflu(x % 2, (x + 1) / 2, (y + 1 - (y - x) % 2) / 2) + sum;
        if (cat < 1)
          ans = 0;
        else if (y > x) {
          cat = aflu((x + 1) % 2, x / 2 + 1, (y + 1) / 2) - sum;
          if (cat < 0) ans = 0;
        }
      }
      fprintf(stdout, "%d\n", ans);
    }
  }
  return 0;
}
