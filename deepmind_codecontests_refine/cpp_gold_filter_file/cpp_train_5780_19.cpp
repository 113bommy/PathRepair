#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct gg {
  int a, b, num;
} g[maxn], out[maxn];
bool cmp(gg g1, gg g2) { return g1.a < g2.a || (g1.a == g2.a && g1.b > g2.b); }
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> g[i].a >> g[i].b;
    g[i].num = i;
  }
  sort(g, g + m, cmp);
  int node = 1;
  int flag = 0;
  int a = 2, b = 3;
  for (int i = 0; i < m; ++i) {
    if (g[i].b) {
      node++;
      out[g[i].num].a = node;
      out[g[i].num].b = 1;
    } else {
      if (1ll * node * (node - 1) / 2ll < i + 1) {
        flag = 1;
        break;
      }
      out[g[i].num].a = a;
      out[g[i].num].b = b;
      if (a == b - 1) {
        b++;
        a = 2;
      } else {
        a++;
      }
    }
  }
  if (flag) {
    cout << "-1\n";
  } else {
    for (int i = 0; i < m; ++i) {
      cout << out[i].a << " " << out[i].b << endl;
    }
  }
  return 0;
}
