#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const double pi = acos(-1.0);
const int v2 = (mod + 1) / 2;
const double eps = 1e-4;
int n;
double w;
struct G {
  int pos, speed;
  int id;
  double ps_w, psw;
} g1[maxn], g2[maxn];
int s[maxn];
bool cmp1(G a, G b) { return a.psw < b.psw; }
bool cmp2(G a, G b) { return a.ps_w < b.ps_w; }
void update(int now) {
  while (now <= n) {
    s[now]++;
    now += (now & -now);
  }
}
int query(int now) {
  int res = 0;
  while (now >= 1) {
    res += s[now];
    now -= (now & -now);
  }
  return res;
}
int main() {
  scanf("%d %lf", &n, &w);
  w += eps;
  for (int i = 1; i <= n; i++) {
    int pos, speed;
    scanf("%d %d", &pos, &speed);
    g1[i].pos = pos;
    g1[i].speed = speed;
    g1[i].psw = 1.0 * g1[i].pos / (g1[i].speed + w);
    g1[i].ps_w = 1.0 * g1[i].pos / (g1[i].speed - w);
  }
  sort(g1 + 1, g1 + n + 1, cmp1);
  for (int i = 1; i <= n; i++) {
    g1[i].id = i;
    g2[i] = g1[i];
  }
  sort(g1 + 1, g1 + n + 1, cmp2);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int id = g1[i].id;
    ans += id - query(id) - 1;
    update(id);
  }
  printf("%lld\n", ans);
  return 0;
}
