#include <bits/stdc++.h>
using namespace std;
int n, fa[210000];
struct Node {
  long long S, R, id;
  bool operator==(Node y) {
    if (S != y.S) return 0;
    if (R != y.R) return 0;
    return 1;
  }
} a[210000];
Node sta[210000];
int Lst[210000];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
long long CROSS_PRODUCT(Node p0, Node p1, Node p2) {
  return p1.S * p2.R * (p0.R - p1.R) * (p0.S - p2.S) -
         p1.R * p2.S * (p0.R - p2.R) * (p0.S - p1.S);
}
bool cmp(Node x, Node y) {
  long long temp = CROSS_PRODUCT(a[1], x, y);
  if (temp) return temp > 0;
  return x.R > y.R;
}
bool visited[210000];
int main() {
  scanf("%d", &n);
  int loc1 = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d%I64d", &a[i].R, &a[i].S);
    a[i].id = i;
    if (a[i].R > a[loc1].R)
      loc1 = i;
    else if (a[i].R == a[loc1].R && a[i].S > a[loc1].S)
      loc1 = i;
    fa[i] = i;
  }
  swap(a[loc1], a[1]);
  if (n >= 2) sort(a + 2, a + 1 + n, cmp);
  int cnt = 1;
  sta[1] = a[1];
  loc1 = 1;
  for (int i = 2; i <= n; ++i) {
    while (cnt > 1) {
      long long temp = CROSS_PRODUCT(sta[cnt - 1], sta[cnt], a[i]);
      if (temp < 0)
        --cnt;
      else if (temp == 0) {
        if (a[i] == sta[cnt]) {
          fa[find(a[i].id)] = find(sta[cnt].id);
          --cnt;
        }
        if (sta[cnt].R == a[i].R || sta[cnt].S == a[i].S)
          --cnt;
        else
          break;
      } else
        break;
    }
    if (a[i] == sta[cnt])
      fa[find(a[i].id)] = find(sta[cnt].id);
    else
      sta[++cnt] = a[i];
  }
  int loc2 = cnt;
  for (int i = cnt; i >= 1; --i) {
    if (sta[i].S > sta[loc2].S)
      loc2 = i;
    else if (sta[i].S == sta[loc2].S && sta[i].R > sta[loc2].R)
      loc2 = i;
  }
  for (int i = loc1; i <= loc2; ++i) {
    visited[find(sta[i].id)] = 1;
  }
  bool flag = 0;
  for (int i = 1; i <= n; ++i)
    if (visited[find(i)]) {
      if (flag)
        printf(" %d", i);
      else
        printf("%d", i), flag = 1;
    }
  puts("");
  return 0;
}
