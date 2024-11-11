#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483646;
const int N = 1005;
int n, k;
int cart[N];
vector<int> c_ans[N];
struct Item {
  int c, t;
  int id;
} it[N];
int cmp(Item x, Item y) { return x.c > y.c; }
int main() {
  int i, j;
  double ans = 0;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &it[i].c, &it[i].t);
    ans += it[i].c;
    it[i].id = i + 1;
  }
  sort(it, it + n, cmp);
  int m = 0;
  memset(cart, -1, sizeof(cart));
  for (i = 0; i < n && m < k; i++) {
    if (it[i].t == 1) {
      cart[i] = m;
      m++;
    }
  }
  for (i = 0; i < n && m < k; i++) {
    if (cart[i] == -1) cart[i] = m++;
  }
  for (i = 0; i < n; i++)
    if (cart[i] == -1) cart[i] = k - 1;
  for (i = 0; i < k; i++) {
    bool has_sto = false;
    int minv = INF;
    for (j = 0; j < n; j++) {
      if (cart[j] == i) {
        minv = min(minv, it[j].c);
        if (it[j].t == 1) has_sto = true;
        c_ans[i].push_back(j);
      }
    }
    if (has_sto) ans -= (minv * 1.0 / 2);
  }
  printf("%.1lf\n", ans);
  for (i = 0; i < k; i++) {
    int tn = c_ans[i].size();
    printf("%d", tn);
    for (j = 0; j < tn; j++) {
      putchar(' ');
      printf("%d", it[c_ans[i][j]].id);
    }
    putchar('\n');
  }
  return 0;
}
