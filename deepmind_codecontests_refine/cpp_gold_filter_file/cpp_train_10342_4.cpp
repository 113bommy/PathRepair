#include <bits/stdc++.h>
using namespace std;
int n, m;
int qu[1005];
bool res[1005];
struct nv {
  int a;
  int b;
  int c;
};
nv ap[10005];
void Nhap() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> qu[i];
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> ap[i].a >> ap[i].b >> ap[i].c;
}
bool ss(nv x, nv y) { return ((x.b < y.b) || (x.b == y.b && x.c < y.c)); }
int main() {
  Nhap();
  int ans = 0;
  sort(ap + 1, ap + m + 1, ss);
  int temp = -1;
  for (int i = 1; i <= m; i++) {
    if (qu[ap[i].a] > qu[ap[i].b] && ap[i].b != temp) {
      res[ap[i].b] = true;
      ans += ap[i].c;
      temp = ap[i].b;
    }
  }
  int dem = 0;
  for (int i = 1; i <= n; i++) {
    if (res[i] == false) dem++;
    if (dem >= 2) {
      cout << -1;
      return 0;
    }
  }
  cout << ans;
}
