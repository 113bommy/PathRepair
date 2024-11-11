#include <bits/stdc++.h>
using namespace std;
const int N(5e5 + 9);
int T, n, m, ans;
int c[N];
map<int, int> M;
struct A {
  int x, y, z;
} a[N];
bool cmp1(A &a, A &b) { return a.x > b.x; }
void add(int id, int val) {
  for (int i = id; i > 0; i -= (i & -i)) {
    c[i] = max(c[i], val);
  }
}
int query(int id) {
  int ret = 0;
  for (int i = id + 1; i <= m; i += (i & -i)) {
    ret = max(ret, c[i]);
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].x);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].y);
    M[a[i].y] = 1;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].z);
  }
  for (auto x : M) {
    M[x.first] = ++m;
  }
  sort(a, a + n, cmp1);
  int i = 0;
  while (i < n) {
    int j = i;
    while (j + 1 < n && a[j].x == a[j + 1].x) {
      int tmp = query(M[a[j].y]);
      if (tmp > a[j].z) {
        ans++;
      }
      j++;
    }
    int tmp = query(M[a[j].y]);
    if (tmp > a[j].z) {
      ans++;
    }
    for (int k = i; k <= j; k++) {
      add(M[a[k].y], a[k].z);
    }
    i = j + 1;
  }
  cout << ans << endl;
  return 0;
}
