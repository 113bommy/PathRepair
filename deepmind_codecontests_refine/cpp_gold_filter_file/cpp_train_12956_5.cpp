#include <bits/stdc++.h>
using namespace std;
int n, q;
int st[100010];
void add(int vt, int val) {
  while (vt <= 100010) {
    st[vt] += val;
    vt |= vt + 1;
  }
}
int sum(int vt) {
  int val;
  val = 0;
  while (vt > 0) {
    val += st[vt - 1];
    vt &= (vt - 1);
  }
  return val;
}
void input() {
  int i, j, x, y, p;
  int dau, cuoi, giua, tp, w, temp, dao;
  scanf("%d %d", &n, &q);
  dau = 0;
  cuoi = n;
  dao = 0;
  for (i = 0; i < n; i++) add(i, 1);
  for (i = 0; i < q; i++) {
    scanf("%d", &tp);
    if (tp == 1) {
      scanf("%d", &p);
      if (dau < cuoi)
        giua = dau + p;
      else
        giua = dau - p;
      if (dau > cuoi) swap(dau, cuoi);
      w = min(giua - dau, cuoi - giua);
      if (giua - dau <= cuoi - giua) {
        for (j = 0; j < w; j++) {
          temp = sum(giua - j) - sum(giua - j - 1);
          add(giua + j, temp);
        }
        dau = giua;
        cuoi = cuoi;
      } else {
        for (j = 0; j < w; j++) {
          temp = sum(giua + j + 1) - sum(giua + j);
          add(giua - j - 1, temp);
        }
        cuoi = dau;
        dau = giua;
      }
    } else {
      scanf("%d %d", &x, &y);
      if (dau < cuoi)
        cout << sum(dau + y) - sum(dau + x) << endl;
      else
        cout << sum(dau - x) - sum(dau - y) << endl;
    }
  }
}
int main() {
  input();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
