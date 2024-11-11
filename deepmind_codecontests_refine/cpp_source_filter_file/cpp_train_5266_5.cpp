#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int n, m, k, f[MAXN], ans[MAXN], c[MAXN * 2];
struct store {
  int date;
  int num;
} s[MAXN];
bool cmp(store a, store b) { return a.date > b.date; }
bool have_drinkall(int a[], int b) {
  int d = 0;
  int cnt = 0;
  for (int i = 1; i <= b; i++) {
    if (d > a[i]) {
      return false;
    }
    cnt++;
    if (cnt == k) {
      cnt = 0;
      d++;
    }
  }
  return true;
}
bool buy(int mid) {
  int num = 0;
  for (int i = 1; i <= n; i++) {
    num++;
    c[num] = f[i];
  }
  for (int i = 1; i <= mid; i++) {
    num++;
    c[num] = s[i].date;
  }
  sort(c + 1, c + 1 + num);
  if (have_drinkall(c, num) == true) {
    for (int i = 1; i <= mid; i++) {
      ans[i] = s[i].num;
    }
    return true;
  } else
    return false;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
  }
  sort(f + 1, f + n + 1);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &s[i].date);
    s[i].num = i;
  }
  sort(s + 1, s + 1 + m, cmp);
  if (have_drinkall(f, n) == false) {
    printf("-1");
    return 0;
  }
  int cnt = 0;
  int left = 1, right = m;
  while (right - left >= 0) {
    int middle = (left + right) / 2;
    if (buy(middle) == true) {
      left = middle + 1;
      cnt = middle;
    } else {
      right = middle - 1;
    }
  }
  printf("%d", cnt);
  for (int i = 1; i <= cnt; i++) {
    printf("%d", ans[i]);
  }
  return 0;
}
