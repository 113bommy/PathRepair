#include <bits/stdc++.h>
using namespace std;
const int Max = 500;
const int def = 0x3f3f3f3f;
char a[500];
long long num[500];
int f[500];
int cnt[500];
int getf(int x) { return f[x] == x ? f[x] : f[x] = getf(f[x]); }
void add(int x, int y) {
  int xx = getf(x);
  int yy = getf(y);
  if (xx != yy) {
    f[xx] = yy;
    cnt[yy] += cnt[xx];
  }
}
int main() {
  long long i, j, h;
  int n, m;
  scanf("%s", a);
  int len = strlen(a);
  for (i = 0; i < len; i++) {
    if (a[i] == 'B' && a[(i + 1) % len] == 'A') a[i] = a[(i + 1) % len] = 'O';
    f[i] = i;
    cnt[i] = 1;
  }
  int flag = 1;
  for (i = 0; i < len; i++) {
    if (a[i] == 'A' && a[(i + 1) % len] == 'B') {
      flag = 0;
      break;
    }
  }
  if (flag == 0) {
    printf("0\n");
    return 0;
  }
  num[0] = 1;
  num[1] = 2;
  for (i = 2; i <= 50; i++) {
    num[i] = num[i - 1] + num[i - 2];
  }
  int notling = 0;
  for (i = 0; i < len; i++) {
    if (a[i] == 'O' && a[(i + 1) % len] == 'O') {
      add(i, i + 1);
      notling = 1;
    }
  }
  if (notling == 0) {
    printf("1\n");
    return 0;
  }
  for (i = 0; i < len; i++) {
    if (f[i] == i && a[i] == 'O') {
      int en = 0;
      if (a[(i + 1) % len] == 'B') en++;
      if (a[(i - cnt[i] + len) % len] == 'A') en++;
      if (cnt[i] == 2 && en)
        cnt[i] = 0;
      else if (cnt[i] > 2)
        cnt[i] -= en * 2;
    }
  }
  for (i = 0; i < len; i++) {
    if (f[i] == i && a[i] == 'O' && cnt[i] == len) break;
  }
  if (i < len) {
    long long ns[110];
    ns[1] = 2;
    ns[2] = 3;
    ns[3] = 4;
    for (i = 4; i <= 50; i++) ns[i] = ns[i - 1] + ns[i - 2];
    printf("%lld\n", ns[len / 2]);
  } else {
    long long shuchu = 1;
    for (i = 0; i < len; i++) {
      if (f[i] == i && a[i] == 'O') shuchu *= num[cnt[i] / 2];
    }
    printf("%lld\n", shuchu);
  }
}
