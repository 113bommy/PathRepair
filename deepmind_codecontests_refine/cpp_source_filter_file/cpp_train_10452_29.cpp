#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
struct node {
  int a;
  int b;
  int id;
  int pos;
} tmp[maxn], no[maxn];
bool cmp1(node a, node b) {
  if (b.b == a.b) return a.a > b.a;
  return a.b < b.b;
}
bool cmp2(node a, node b) {
  if (a.a == b.a) return a.b > b.b;
  return a.a > b.a;
}
int main() {
  int n, p, k;
  while (scanf("%d %d %d", &n, &p, &k) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &no[i].a, &no[i].b);
      no[i].id = i + 1;
    }
    sort(no, no + n, cmp1);
    for (int i = 0; i < n; i++) {
      no[i].pos = i;
      tmp[i] = no[i];
    }
    sort(no + p - k, no + n, cmp2);
    int t = inf;
    for (int i = p - k, j = 0; j < k; i++, j++) {
      printf("%d ", no[i].id);
      t = min(t, no[i].pos);
    }
    for (int i = t - 1, j = 0; j < p - k; j++, i++) {
      printf("%d ", tmp[i].id);
    }
    puts("");
  }
  return 0;
}
