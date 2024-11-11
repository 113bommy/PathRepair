#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
long long suma, sumb;
int b[maxn], n;
int ans1[maxn * 5], ans2[maxn * 5], ans3[maxn * 5];
struct node {
  int id, v;
  node() {}
  node(int id, int v) : id(id), v(v) {}
  bool operator<(const node &a) const { return v < a.v; }
} e[maxn];
vector<node> ve;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &e[i].v);
    suma += e[i].v;
    e[i].id = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    sumb += b[i];
  }
  if (suma != sumb) {
    return 0 * printf("NO\n");
  }
  sort(b + 1, b + 1 + n);
  sort(e + 1, e + 1 + n);
  bool ok = true;
  int m = 0;
  for (int i = 1; i <= n; i++) {
    if (!ok) break;
    int needadd = b[i] - e[i].v;
    if (needadd == 0) continue;
    if (needadd > 0)
      ve.push_back(node(e[i].id, needadd));
    else {
      while (needadd < 0) {
        if (ve.empty()) {
          ok = false;
          break;
        }
        int la = ve.size() - 1;
        int fin = min(-needadd, ve[la].v);
        ve[la].v -= fin;
        if (ve[la].v == 0) ve.pop_back();
        needadd += fin;
        m++;
        ans1[m] = e[i].id, ans2[m] = ve[la].id, ans3[m] = fin;
      }
    }
  }
  if (!ok || ve.size()) return 0 * printf("NO\n");
  printf("YES\n%d\n", m);
  for (int i = 1; i <= m; i++) {
    printf("%d %d %d\n", ans1[i], ans2[i], ans3[i]);
  }
  return 0;
}
