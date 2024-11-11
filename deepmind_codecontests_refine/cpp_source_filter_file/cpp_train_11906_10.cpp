#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
int n, m, q, i, j, ans[500005];
bitset<505> f[505][505], g[505][505];
char mp[505][505];
struct qry {
  int x, y, xx, yy, id;
};
vector<qry> v;
void solve(vector<qry> v, int l, int r) {
  if (l > r || v.empty()) return;
  int mid = (l + r) / 2;
  int i, j, k;
  for ((i) = (l); (i) <= (r); (i)++)
    for (((j)) = (1); ((j)) <= ((m)); ((j))++) {
      f[i][j].reset();
      g[i][j].reset();
    }
  for (((j)) = (1); ((j)) <= ((m)); ((j))++)
    if (mp[mid][j] == '.') {
      f[mid][j][j] = 1;
      g[mid][j][j] = 1;
    }
  for (((j)) = ((m)); ((j)) >= (1); ((j))--)
    if (mp[mid][j] == '.') {
      f[mid][j] |= f[mid][j + 1];
    }
  for (((j)) = (1); ((j)) <= ((m)); ((j))++)
    if (mp[mid][j] == '.') {
      g[mid][j] |= g[mid][j - 1];
    }
  for ((i) = (mid - 1); (i) >= (l); (i)--) {
    for (((j)) = ((m)); ((j)) >= (1); ((j))--)
      if (mp[i][j] == '.') {
        f[i][j] = (f[i + 1][j] | f[i][j + 1]);
      }
  }
  for ((i) = (mid + 1); (i) <= (r); (i)++) {
    for (((j)) = (1); ((j)) <= ((m)); ((j))++)
      if (mp[i][j] == '.') {
        g[i][j] = (g[i - 1][j] | g[i][j - 1]);
      }
  }
  vector<qry> vl, vr;
  for (i = 0; i < v.size(); i++) {
    if (v[i].x <= mid && v[i].xx >= mid) {
      ans[v[i].id] = (f[v[i].x][v[i].y] & g[v[i].xx][v[i].yy]).count();
    } else {
      if (v[i].xx < mid) {
        vl.push_back(v[i]);
      } else {
        vr.push_back(v[i]);
      }
    }
  }
  solve(vl, l, mid - 1);
  solve(vr, mid + 1, r);
}
int main() {
  scanf("%d%d", &n, &m);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    scanf(" ");
    for (((j)) = (1); ((j)) <= ((m)); ((j))++) {
      scanf("%c", &mp[i][j]);
    }
  }
  scanf("%d", &q);
  for (((i)) = (1); ((i)) <= ((q)); ((i))++) {
    qry t;
    scanf("%d%d%d%d", &t.x, &t.y, &t.xx, &t.yy);
    if (t.x > t.xx) {
      swap(t.x, t.xx);
      swap(t.y, t.yy);
    }
    t.id = i;
    v.push_back(t);
  }
  solve(v, 1, n);
  for (((i)) = (1); ((i)) <= ((q)); ((i))++) {
    if (ans[i])
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
