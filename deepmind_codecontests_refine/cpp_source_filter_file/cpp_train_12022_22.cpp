#include <bits/stdc++.h>
using namespace std;
int L[7], R[7];
double tot = 1;
int n;
int t[7];
int cnt[4];
double ans = 0;
double tmp = 0;
int nchoose(int pos, int left, int right) {
  if (L[pos] > right || left > R[pos]) return 0;
  return min(R[pos], right) - max(L[pos], left) + 1;
}
void back(int k, int price) {
  if (k == n) {
    memset(cnt, 0, sizeof cnt);
    double tmo = 1;
    for (int i = 1; i <= n; i++) cnt[t[i]]++;
    if (cnt[1] > 1) return;
    if (cnt[1] == 0 && cnt[2] <= 1) return;
    if (cnt[2] == 0) return;
    for (int i = 1; i <= 3; i++) {
      if (t[i] == 1)
        tmo *= nchoose(i, price + 1, 10000);
      else if (t[i] == 2)
        tmo *= nchoose(i, price, price);
      else
        tmo *= nchoose(i, 1, price - 1);
    }
    tmp += tmo;
  } else {
    k++;
    for (int i = 1; i <= 3; i++) {
      t[k] = i;
      back(k, price);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d %d", &L[i], &R[i]);
  for (int i = 1; i <= n; i++) tot *= (R[i] - L[i] + 1);
  for (int i = 1; i <= 10000; i++) {
    tmp = 0;
    back(0, i);
    ans += tmp * i;
  }
  printf("%.12lf", ans / tot);
}
