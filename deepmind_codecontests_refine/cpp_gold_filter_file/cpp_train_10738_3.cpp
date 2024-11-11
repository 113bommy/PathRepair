#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 51;
int cnt, k, tmp;
int num[MAXN];
inline int read() {
  register int num = 0, neg = 1;
  register char ch = getchar();
  while (!isdigit(ch) && ch != '-') {
    ch = getchar();
  }
  if (ch == '-') {
    neg = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = (num << 3) + (num << 1) + (ch - '0');
    ch = getchar();
  }
  return num * neg;
}
int main() {
  cnt = read(), k = read();
  for (register int i = 0; i < cnt; i++) {
    num[i] = read();
  }
  sort(num, num + cnt);
  for (register int i = 0; i < cnt; i++) {
    if (num[i] - k >= num[tmp]) {
      tmp++;
    }
  }
  printf("%d\n", min(tmp, cnt >> 1));
}
