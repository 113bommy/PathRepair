#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct block {
  int l, r, pre, nex, cnt, f[N];
} bl[320];
int a[N], n, num, dd[N];
int solve(int k) {
  int res = 1, pre = 1, cnt = 0;
  memset(dd, 0, sizeof dd);
  for (int i = 1; i <= n; i++) {
    if (dd[a[i]])
      dd[a[i]]++;
    else if (cnt < k) {
      dd[a[i]]++;
      cnt++;
    } else {
      for (int j = pre; j <= i - 1; j++) dd[a[j]] = 0;
      pre = i;
      res++;
      dd[a[i]] = cnt = 1;
    }
  }
  return res;
}
void init(int k) {
  num = bl[1].l = 1;
  for (int i = 1; i <= n; i++) {
    if (bl[num].f[a[i]])
      bl[num].f[a[i]]++;
    else if (bl[num].cnt < k) {
      bl[num].f[a[i]]++;
      bl[num].cnt++;
    } else {
      bl[num++].r = i - 1;
      bl[num].l = i;
      bl[num].f[a[i]] = bl[num].cnt = 1;
    }
  }
  bl[num].r = n;
  for (int i = 1; i <= num; i++) {
    bl[i].pre = i - 1;
    bl[i].nex = i + 1;
  }
}
int bl_solve(int k) {
  int res = 1;
  for (int i = bl[1].nex; i <= num; i = bl[i].nex) {
    int pre = bl[i].pre, nex = bl[i].nex;
    for (int j = bl[i].l; j <= bl[i].r + 1; j++) {
      if (j <= bl[i].r && (bl[pre].f[a[j]] || bl[pre].cnt < k)) {
        if (!bl[pre].f[a[j]]) bl[pre].cnt++;
        bl[pre].f[a[j]]++;
        bl[i].f[a[j]]--;
        if (!bl[i].f[a[j]]) bl[i].cnt--;
        bl[pre].r = j;
      } else {
        bl[i].l = j;
        break;
      }
    }
    if (bl[i].l <= bl[i].r)
      res++;
    else {
      bl[pre].nex = nex;
      bl[nex].pre = pre;
    }
  }
  return res;
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= min(n, 317); i++) cout << solve(i) << ' ';
  if (n <= 317) return 0;
  init(317);
  for (int i = 318; i <= n; i++) cout << bl_solve(i) << ' ';
}
