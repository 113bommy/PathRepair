#include <bits/stdc++.h>
const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int inf = 0x3f3f3f3f;
using namespace std;
char s1[MAXN], s2[MAXN];
int tot[MAXN * 2], to;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    to = 0;
    scanf("%d", &n);
    scanf("%s", s1 + 1);
    scanf("%s", s2 + 1);
    int ans = 0;
    int need;
    for (need = n; need >= 1; need--) {
      if (s1[need] != s2[need]) {
        break;
      }
    }
    int l = 1, r = need, flag = 1;
    while (need) {
      if (flag) {
        if (s1[l] != s2[need]) {
          tot[to++] = r;
        } else {
          tot[to++] = 1;
          tot[to++] = r;
        }
        l++;
      } else {
        char x = s1[r];
        if (x == '0')
          x = '1';
        else
          x = '0';
        if (x != s2[need]) {
          tot[to++] = need;
        } else {
          tot[to++] = 1;
          tot[to++] = need;
        }
        r--;
      }
      flag ^= 1;
      need--;
    }
    printf("%d ", to);
    for (int i = 0; i < to; i++) printf("%d ", tot[i]);
    printf("\n");
  }
  return 0;
}
