#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  bool operator<(const P &a) const {
    if (x != a.x) return x < a.x;
    return y < a.y;
  }
};
vector<int> v[411111];
int i, n, m, k, a, d, b, c;
int e;
int o[411111];
int j[411111];
int l[411111];
int dx[10] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[10] = {1, 0, -1, 0, 1, -1, 1, -1},
    dz[10] = {0, 0, 0, 0, 1, -1};
int px[10] = {-1, 1, 1, -1, 1, 1, -1, -1},
    py[10] = {1, 1, -1, -1, 1, -1, 1, -1};
long long mod = 1000000007, mod2 = 1000000009, mod3 = 2017;
long long x, z, y;
double pi = 3.14159265;
P u[1];
stack<int> s;
queue<int> q;
char r[1111];
map<int, int> p;
bool as(P a, P b) { return a.x > b.x; }
int main() {
  scanf("%d %d", &a, &b);
  for (int t = 1; t <= a; k += o[t], t++) scanf("%d", &o[t]);
  for (int t = 1; t <= b; t++) {
    scanf("%d %d", &n, &m);
    v[n].push_back(m);
  }
  n = 1, m = 2 * k;
  for (; n < m;) {
    int h = (n + m) / 2;
    memset(j, 0, sizeof(j));
    for (int t = h; t > 0; t--)
      for (int i = 0; i < v[t].size(); i++)
        if (!j[v[t][i]]) j[v[t][i]] = t;
    int c = 0, d = 0;
    for (int t = 1; t <= h; t++) {
      c++;
      for (int i = 0; i < v[t].size(); i++)
        if (j[v[t][i]] == t) {
          d += min(c, o[v[t][i]]);
          c -= min(c, o[v[t][i]]);
          j[v[t][i]] = 0;
        }
    }
    d += c / 2;
    if (d >= k)
      m = h;
    else
      n = h + 1;
  }
  printf("%d", n);
}
