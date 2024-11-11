#include <bits/stdc++.h>
using namespace std;
int mang[5][600010];
int mchay[5];
int a[40];
int n, m;
int kq;
void vaomang(int bd, int kt, int vt) {
  int i, j;
  int tg;
  mchay[vt] = 0;
  for (i = bd; i <= kt; i++) {
    tg = mchay[vt];
    for (j = 0; j < tg; j++) {
      mang[vt][mchay[vt]] = mang[vt][j] + a[i];
      mang[vt][mchay[vt]] %= m;
      mchay[vt]++;
    }
    mang[vt][mchay[vt]] = a[i] % m;
    mchay[vt]++;
  }
}
bool cmp(int x, int y) { return x < y; }
void bophantu() {
  int i;
  int chay;
  chay = 1;
  for (i = 1; i < mchay[1]; i++) {
    if (mang[1][i] != mang[1][chay]) {
      mang[1][chay] = mang[1][i];
      chay++;
    }
  }
  mchay[1] = chay;
}
int tinh(int gt, int maxx) {
  int x;
  int dau, giua, cuoi;
  dau = 0;
  cuoi = mchay[1];
  x = 0;
  while (dau <= cuoi) {
    giua = (dau + cuoi) / 2;
    if (mang[1][giua] >= maxx) {
      cuoi = giua - 1;
    } else {
      x = mang[1][giua];
      dau = giua + 1;
    }
  }
  return x;
}
int khoitri() {
  int i, j;
  int maxx;
  maxx = 0;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < mchay[i]; j++) {
      maxx = max(maxx, mang[i][j]);
    }
  }
  return maxx;
}
void solve() {
  int i;
  int giua, gt1, gt2;
  if (n == 1) {
    kq = a[1] % m;
    return;
  }
  giua = n / 2;
  vaomang(1, giua, 0);
  vaomang(giua + 1, n, 1);
  sort(mang[1], mang[1] + mchay[1], cmp);
  bophantu();
  kq = khoitri();
  for (i = 0; i < mchay[0]; i++) {
    gt1 = (mang[0][i] + mang[1][mchay[1] - 1]) % m;
    gt2 = (mang[0][i] + tinh(mang[0][i], m - mang[0][i])) % m;
    kq = max(kq, max(gt1, gt2));
  }
}
void output() { printf("%d\n", kq); }
int main() {
  int i;
  while (scanf("%d %d", &n, &m) > 0) {
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    solve();
    output();
  }
  return 0;
}
