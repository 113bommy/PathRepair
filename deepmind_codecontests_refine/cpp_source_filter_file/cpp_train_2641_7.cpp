#include <bits/stdc++.h>
using namespace std;
char str[555555];
int tot = 0;
int seg[555555];
bool verify(int n, int t, int k) {
  long long ct = 0;
  int seglen = 0;
  int sent = 0;
  int waiting = 0;
  int scnt = 0;
  for (int i = 0; i < n && sent < tot; i++) {
    seglen++;
    if (str[i] == 'S') {
      if (k == -1) {
        ct += seglen * 3 - 2;
        seg[scnt++] = seglen;
        seglen = 0;
      }
      k++;
    } else if (str[i] == '.') {
    } else if (str[i] == 'H') {
      k--;
      waiting++;
    }
    if (k >= 0) {
      ct += seglen;
      if (seglen) seg[scnt++] = 0;
      seglen = 0;
      sent += waiting;
      waiting = 0;
    }
  }
  long long tct = ct;
  while (scnt) {
    ct -= seg[--scnt] - 1;
    ct = min(ct, tct);
  }
  return ct <= t && k >= 0;
}
int main(void) {
  int n = 0;
  int t = 0;
  scanf("%d %d %s", &n, &t, str);
  for (int i = 0; i < n; i++) tot += str[i] == 'H';
  int l = 0;
  int r = n + 10;
  while (l < r) {
    int mid = (l + r) / 2;
    if (verify(n, t, mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (l > n)
    puts("-1");
  else
    printf("%d\n", l);
  while (getchar() != EOF)
    ;
  return 0;
}
