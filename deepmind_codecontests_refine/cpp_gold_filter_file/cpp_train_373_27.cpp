#include <bits/stdc++.h>
using namespace std;
struct ss {
  int num;
  long long sum[5];
} ans[300000];
char s1[10];
int n, m;
int q1[300000], q2[300000], a[300000];
void ins(int l, int r, int pos, int k, int val) {
  if (l == r) {
    ans[k].num = 1;
    for (int i = 0; i < 5; i++) ans[k].sum[i] = 0;
    ans[k].sum[1] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (mid < pos)
    ins(mid + 1, r, pos, 2 * k + 1, val);
  else
    ins(l, mid, pos, 2 * k, val);
  ans[k].num++;
  int x = 5 - ans[k * 2].num % 5;
  for (int i = 0; i < 5; i++)
    ans[k].sum[i] = ans[k * 2].sum[i] + ans[k * 2 + 1].sum[(i + x) % 5];
}
void del(int l, int r, int pos, int k, int val) {
  if (l == r) {
    ans[k].num = 0;
    for (int i = 0; i < 5; i++) ans[k].sum[i] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  if (mid < pos)
    del(mid + 1, r, pos, 2 * k + 1, val);
  else
    del(l, mid, pos, 2 * k, val);
  ans[k].num--;
  int x = 5 - ans[k * 2].num % 5;
  for (int i = 0; i < 5; i++)
    ans[k].sum[i] = ans[k * 2].sum[i] + ans[k * 2 + 1].sum[(i + x) % 5];
}
int main() {
  scanf("%d", &n);
  m = -1;
  for (int i = 0; i < n; i++) {
    scanf("%s", &s1);
    int x;
    if (*s1 == 's')
      q1[i] = 0;
    else if (*s1 == 'a') {
      scanf("%d", &x);
      q1[i] = 1;
      q2[i] = x;
      m++;
      a[m] = x;
    } else {
      scanf("%d", &x);
      q1[i] = 2;
      q2[i] = x;
    }
  }
  m++;
  sort(a, a + m);
  int k = 1;
  while (k < m) {
    k <<= 1;
  }
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < n; i++) {
    if (q1[i] == 0) {
      printf("%I64d\n", ans[1].sum[3]);
    } else {
      int x, l = 0, r = m, mid;
      while (l < r) {
        mid = (l + r) / 2;
        if (a[mid] == q2[i]) break;
        if (a[mid] < q2[i])
          l = mid;
        else
          r = mid;
      }
      x = mid + 1;
      if (q1[i] == 1)
        ins(1, k, x, 1, q2[i]);
      else
        del(1, k, x, 1, q2[i]);
    }
  }
  return 0;
}
