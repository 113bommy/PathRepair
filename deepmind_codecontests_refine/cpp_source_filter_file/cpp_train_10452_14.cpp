#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 10;
int n, p, k;
struct Ord {
  int a, b;
  int id;
} ord[Maxn];
int id[Maxn];
bool cmp1(const Ord &x, const Ord &y) {
  if (x.b == y.b) return x.a > y.a;
  return x.b > y.b;
}
bool cmp2(int x, int y) {
  if (ord[x].a == ord[y].a) return ord[x].b > ord[y].b;
  return ord[x].a > ord[y].a;
}
void out() {
  for (int i = 0; i < n; ++i) cout << ord[i].a << " " << ord[i].b << endl;
}
int main() {
  while (scanf("%d%d%d", &n, &p, &k) != EOF) {
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &ord[i].a, &ord[i].b);
      ord[i].id = i + 1;
      id[i] = i;
    }
    sort(ord, ord + n, cmp1);
    sort(id, id + n - p + k, cmp2);
    int maxid = 0;
    for (int i = 0; i < k; ++i) {
      printf("%d ", ord[id[i]].id);
      maxid = max(maxid, id[i]);
    }
    for (int i = 1; i <= p - k; ++i) printf("%d ", ord[maxid + i].id);
    puts("");
  }
  return 0;
}
