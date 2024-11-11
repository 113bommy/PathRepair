#include <bits/stdc++.h>
using namespace std;
const int N = 2005, inf = 0x3f3f3f3f;
int n, m, pos[N];
long long S;
struct vec {
  long long x, y;
  void read() { scanf("%I64d %I64d", &x, &y); }
  void print() { printf("%I64d %I64d\n", x, y); }
} a[N];
struct node {
  int x, y;
  vec f;
} f[N * N];
vec operator+(vec a, vec b) { return (vec){a.x + b.x, a.y + b.y}; }
vec operator-(vec a, vec b) { return (vec){a.x - b.x, a.y - b.y}; }
long long operator^(vec a, vec b) { return a.x * b.y - a.y * b.x; }
int getquad(vec a) {
  if ((a.x > 0) && (a.y >= 0)) return 1;
  if ((a.x <= 0) && (a.y > 0)) return 2;
  if ((a.x < 0) && (a.y <= 0)) return 3;
  if ((a.x >= 0) && (a.y < 0)) return 4;
  return 0;
}
bool cmp1(node a, node b) {
  int ta = getquad(a.f), tb = getquad(b.f);
  return (ta != tb) ? (ta < tb) : ((a.f ^ b.f) > 0);
}
bool cmp(vec a, vec b) { return (a.y != b.y) ? (a.y < b.y) : (a.x < b.x); }
void print(int x, int y, int z) {
  puts("Yes");
  a[x].print();
  a[y].print();
  a[z].print();
}
long long check(vec x, node f) { return (f.f ^ (x - a[pos[f.x]])); }
bool work(int l, int r, node f) {
  if (r < l) return false;
  int mid = (l + r) >> 1;
  long long s = check(a[mid], f);
  if (s == S) {
    print(mid, pos[f.x], pos[f.y]);
    return true;
  } else if (s < S)
    return work(mid + 1, r, f);
  else
    return work(l, mid - 1, f);
}
int main() {
  scanf("%d %I64d", &n, &S);
  S *= 2;
  for (int i = 1; i <= n; i++) a[i].read();
  sort(a + 1, a + m + 1, cmp);
  for (int i = 1; i <= n; i++) pos[i] = i;
  m = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) {
        f[++m].x = i;
        f[m].y = j;
        f[m].f = a[j] - a[i];
      }
  sort(f + 1, f + m + 1, cmp1);
  for (int i = 1; i <= m; i++) {
    if (work(1, n, f[i])) return 0;
    int l = pos[f[i].x], r = pos[f[i].y];
    swap(a[l], a[r]);
    swap(pos[f[i].x], pos[f[i].y]);
  }
  puts("No");
  return 0;
}
