#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
template <class T>
bool inside(T a, T b, T c) {
  return (b >= a && b <= c);
}
const long long INF64 = (long long)1E16;
int distsq2d(int x1, int y1, int x2, int y2) {
  return sqr(x1 - x2) + sqr(y1 - y2);
}
double dist2d(double x1, double y1, double x2, double y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}
double dist3d(double x1, double y1, double z1, double x2, double y2,
              double z2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2) + sqr(z1 - z2));
}
long long toInt64(string s) {
  long long r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
double LOG(long long N, long long B) { return (log10l(N)) / (log10l(B)); }
string itoa(long long a) {
  if (a == 0) return "0";
  string ret;
  for (long long i = a; i > 0; i = i / 10) ret.push_back((i % 10) + 48);
  reverse(ret.begin(), ret.end());
  return ret;
}
vector<string> token(string a, string b) {
  const char *q = a.c_str();
  while (count(b.begin(), b.end(), *q)) q++;
  vector<string> oot;
  while (*q) {
    const char *e = q;
    while (*e && !count(b.begin(), b.end(), *e)) e++;
    oot.push_back(string(q, e));
    q = e;
    while (count(b.begin(), b.end(), *q)) q++;
  }
  return oot;
}
int isvowel(char s) {
  s = tolower(s);
  if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return 1;
  return 0;
}
int isupper(char s) {
  if (s >= 'A' and s <= 'Z') return 1;
  return 0;
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
int check(int N, int pos) { return (N & (1 << pos)); }
int toggle(int N, int pos) {
  if (check(N, pos)) return N = reset(N, pos);
  return N = Set(N, pos);
}
void pbit(int N) {
  printf("(");
  for (int i = 10; i >= 0; i--) {
    bool x = check(N, i);
    cout << x;
  }
  puts(")");
}
char mat[55][55];
int color[55][55];
int flag = 0;
vector<int> g[2566];
int d[2566], lo[2566], timer = 0, cut[2566];
void dfs(int root, int par, int u) {
  int child = 0;
  timer++;
  d[u] = lo[u] = timer;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (v == par) continue;
    if (d[v] != 0)
      lo[u] = min(lo[u], d[v]);
    else {
      child++;
      dfs(root, u, v);
      lo[u] = min(lo[u], lo[v]);
      if (u != root and lo[v] >= d[u]) {
        flag = 1;
        cut[u] = 1;
      }
    }
  }
  if (u == root and child > 1) {
    flag = 1;
    cut[u] = 1;
  }
}
int fx[] = {0, 0, 1, -1};
int fy[] = {-1, 1, 0, 0};
int main() {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) scanf("%s", mat[i]);
    memset(color, -1, sizeof(color));
    ;
    int mark = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == '#') color[i][j] = ++mark;
      }
    if (mark <= 2) {
      cout << -1 << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (color[i][j] == -1) continue;
        for (int k = 0; k < 4; k++) {
          int tx = i + fx[k];
          int ty = j + fy[k];
          if (tx >= 0 and tx < n and ty >= 0 and ty < m and
              color[tx][ty] != -1) {
            int u = color[i][j];
            int v = color[tx][ty];
            g[u].push_back(v);
          }
        }
      }
    }
    dfs(1, -1, 1);
    if (flag)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
