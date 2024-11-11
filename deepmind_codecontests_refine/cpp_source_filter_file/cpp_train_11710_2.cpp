#include <bits/stdc++.h>
using namespace std;
struct bg {
  int x, w, y, z;
};
const int nm = 200002;
int n;
bg a[nm];
int b[2 * nm];
int tree[nm];
map<int, int> c;
bool cmp(bg a, bg b) { return a.x + a.w < b.x + b.w; }
bool cmp2(bg a, bg b) { return a.x < b.x; }
void update(int i, int j) {
  while (i < nm) {
    tree[i] = max(tree[i], j);
    i += i & (-i);
  }
}
int get(int i) {
  int kq = 0;
  while (i > 0) {
    kq = max(kq, tree[i]);
    i -= i & (-i);
  }
  return kq;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].x, &a[i].w);
    b[2 * i - 1] = a[i].x + a[i].w;
    b[2 * i] = a[i].x - a[i].w;
  }
  sort(b + 1, b + 2 * n + 1);
  int d = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    if (i == 1 || b[i] > b[i - 1]) c[b[i]] = ++d;
  }
  sort(a + 1, a + n + 1, cmp2);
  for (int i = 1; i <= n; ++i) {
    a[i].y = c[a[i].x + a[i].w];
    a[i].z = c[a[i].x - a[i].w];
  }
  int kq = 1;
  update(a[1].y, 1);
  for (int i = 2; i <= n; ++i) {
    int j = get(a[i].z);
    kq = max(kq, j + 1);
    update(a[i].y, j + 1);
  }
  cout << kq << "\n";
}
