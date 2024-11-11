#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
char s[N];
int val[N], tp[N], k, b[N];
bool cmp(int x, int y) { return val[x] < val[y]; }
int main() {
  int a;
  scanf("%d%s", &a, s);
  int len = strlen(s), i, j, eg = 1;
  for (j = -1, i = 0; i < len; i = j + 1) {
    int h;
    for (h = i; h < len; h++)
      if (s[h] == 'a') break;
    if (h >= 2 && s[h - 1] == '+' && s[h - 2] == '+' && h - 2 > j) {
      tp[k] = 0;
      if (h >= 3 && s[h - 3] == '*') {
        int r = 0, e = 1, z;
        for (z = h - 4; z >= 0 && s[z] >= '0' && s[z] <= '9'; z--, e *= 10) {
          r += (s[z] - '0') * e;
        }
        val[k] = eg * r;
      } else
        val[k] = eg;
      k++;
      j = h;
      if (j + 1 < len) {
        if (s[j + 1] == '-')
          eg = -1;
        else
          eg = 1;
      }
    } else {
      tp[k] = 1;
      if (h >= 1 && s[h - 1] == '*') {
        int r = 0, e = 1, z;
        for (z = h - 2; z >= 0 && s[z] >= '0' && s[z] <= '9'; z--, e *= 10) {
          r += (s[z] - '0') * e;
        }
        val[k] = eg * r;
      } else
        val[k] = eg;
      k++;
      j = h + 2;
      if (j + 1 < len) {
        if (s[j + 1] == '-')
          eg = -1;
        else
          eg = 1;
      }
    }
  }
  int ret = 0;
  for (i = 0; i < k; i++) b[i] = i;
  sort(b, b + k, cmp);
  for (int h = 0; h < k; h++) {
    i = b[h];
    int nw;
    if (tp[i] == 0)
      nw = a + 1;
    else
      nw = a;
    ret += nw * val[i];
    a++;
  }
  printf("%d\n", ret);
  return 0;
}
