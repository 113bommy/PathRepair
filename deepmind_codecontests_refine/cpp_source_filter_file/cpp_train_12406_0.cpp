#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int lv = 10;
int a[maxn];
char c[maxn];
int b[10][25];
int n;
int k;
int now[maxn];
int ne[maxn];
int cmp() {
  for (int i = 1; i <= n; i++)
    if (ne[i] < now[i])
      return 1;
    else if (ne[i] > now[i])
      return 0;
  return 0;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", c + 1);
  for (int i = 1; i <= n; i++) a[i] = c[i] - '0';
  for (int num = 0; num <= 9; num++) {
    for (int i = 1; i <= n; i++) {
      int x = a[i] - num;
      x += lv;
      b[num][x]++;
    }
  }
  int t;
  int ans = 0x3f3f3f3f;
  int tar = -1;
  int mr, last;
  memcpy(now, a, sizeof a);
  for (int num = 0; num <= 9; num++) {
    t = k;
    t -= b[num][10];
    if (t <= 0) {
      tar = num;
      ans = 0;
      last = 0;
      mr = 0;
      memcpy(now, a, sizeof a);
      break;
    }
    int val = 0;
    for (int i = 1; i <= 9; i++) {
      int x = 0;
      x += b[num][lv + i];
      x += b[num][lv - i];
      if ((t - x) <= 0) {
        val += (t * i);
        if (val < ans) {
          memcpy(now, a, sizeof a);
          ans = val;
          tar = num;
          mr = i;
          last = t;
          int bigger = 0, litter = 0;
          for (int i = 1; i <= n; i++) {
            if (abs(a[i] - tar) < mr) now[i] = tar;
            if (abs(a[i] - tar) == mr) {
              if (a[i] - tar > 0)
                bigger++;
              else
                litter++;
            }
          }
          if (bigger > last) {
            for (int i = 1; i <= n; i++) {
              if (a[i] - tar == mr) now[i] = tar, last--;
              if (last <= 0) break;
            }
          } else if (bigger == last) {
            for (int i = 1; i <= n; i++)
              if (a[i] - tar == mr) now[i] = tar;
          } else {
            for (int i = 1; i <= n; i++)
              if (a[i] - tar == mr) now[i] = tar, last--;
            for (int i = n; i >= 1; i--) {
              if (tar - a[i] == mr) now[i] = tar, last--;
              if (last <= 0) break;
            }
          }
        } else if (val == ans) {
          int mmr = i;
          int tmp = num;
          int llast = t;
          memcpy(ne, a, sizeof a);
          int bigger = 0, litter = 0;
          for (int i = 1; i <= n; i++) {
            if (abs(ne[i] - tmp) < mr) ne[i] = tmp;
            if (abs(ne[i] - tmp) == mr) {
              if (ne[i] - tmp > 0)
                bigger++;
              else
                litter++;
            }
          }
          if (bigger > llast) {
            for (int i = 1; i <= n; i++) {
              if (ne[i] - tmp == mmr) ne[i] = tmp, llast--;
              if (llast <= 0) break;
            }
          } else if (bigger == llast) {
            for (int i = 1; i <= n; i++)
              if (ne[i] - tmp == mmr) ne[i] = tmp;
          } else {
            for (int i = 1; i <= n; i++)
              if (ne[i] - tmp == mmr) ne[i] = tmp, llast--;
            for (int i = n; i >= 1; i--) {
              if (tmp - ne[i] == mmr) ne[i] = tmp, llast--;
              if (llast <= 0) break;
            }
          }
          if (cmp() == 1) {
            for (int i = 1; i <= n; i++) now[i] = ne[i];
          }
          mr = mmr;
          tar = tmp;
          last = llast;
        }
        break;
      }
      val += (x * i);
      t = t - x;
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) printf("%d", now[i]);
  return 0;
}
