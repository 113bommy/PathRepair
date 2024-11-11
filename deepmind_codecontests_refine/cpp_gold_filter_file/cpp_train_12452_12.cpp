#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N];
int as[N], p[N];
int main() {
  int n = 0;
  scanf("%d", &n);
  scanf("%s", s);
  int acnt = 0, pcnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'P') {
      p[pcnt++] = i;
    } else if (s[i] == '*') {
      as[acnt++] = i;
    }
  }
  int l = 1, r = n * 2, res = n * 2;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int pre = 0;
    for (int i = 0; i < pcnt; ++i) {
      if (p[i] > as[pre]) {
        int cost = p[i] - as[pre];
        if (cost > mid) {
          break;
        } else {
          int tmp = max(mid - 2 * cost, (mid - cost) / 2);
          while (pre < acnt) {
            if (as[pre] <= p[i] + tmp) {
              ++pre;
            } else {
              break;
            }
          }
        }
      } else {
        while (pre < acnt) {
          if (as[pre] <= p[i] + mid) {
            ++pre;
          } else {
            break;
          }
        }
      }
      if (pre == acnt) {
        break;
      }
    }
    if (pre < acnt) {
      l = mid + 1;
    } else {
      res = mid;
      r = mid - 1;
    }
  }
  printf("%d", res);
  return 0;
}
