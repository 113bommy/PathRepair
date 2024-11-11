#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100105;
const double PI = acos(-1.0);
const double eps = 1e-6;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
int h[50005], n, m, f[15005], g[15005], cnt = 0, check[50005];
char s[N], t[N], st[N];
queue<int> Q;
bool p[50005];
void work(char s[], char c) {
  int num = (c < 'A' ? c - '0' : c - 'A' + 10);
  s[3] = '0' + (num & 1);
  num >>= 1;
  s[2] = '0' + (num & 1);
  num >>= 1;
  s[1] = '0' + (num & 1);
  num >>= 1;
  s[0] = '0' + num;
}
int _find(int x) { return h[x] == x ? x : h[x] = _find(h[x]); }
bool U(int &x, int &y) {
  x = _find(x), y = _find(y);
  if (x == y) return 0;
  h[x] = y;
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (0); i <= (m + 5); ++i) s[i] = '0';
  for (int i = (1); i <= (2 * m); ++i) Q.push(h[i] = i);
  memset(p, 1, sizeof(p));
  for (int _t = (1); _t <= (n); ++_t) {
    scanf("%s", st + 1);
    for (int i = (1); i <= (m / 4); ++i) work(t + (i - 1) * 4 + 1, st[i]);
    for (int i = (1); i <= (m); ++i)
      if (t[i] == '1') {
        if (s[i] == '1') {
          g[i] = f[i];
          continue;
        }
        g[i] = Q.front();
        Q.pop();
        cnt++;
        p[g[i]] = 0;
      }
    for (int i = (2); i <= (m); ++i)
      if (t[i] == '1' && t[i - 1] == '1') cnt -= U(g[i], g[i - 1]);
    for (int i = (1); i <= (m); ++i)
      if (t[i] == '1') g[i] = _find(g[i]);
    for (int i = (1); i <= (m); ++i)
      if (t[i] == '1') check[g[i]] = _t;
    for (int i = (1); i <= (2 * m); ++i)
      if (check[i] != _t) {
        h[i] = i;
        if (!p[i]) Q.push(i), p[i] = 1;
      }
    swap(s, t);
    swap(f, g);
  }
  printf("%d\n", cnt);
  return 0;
}
