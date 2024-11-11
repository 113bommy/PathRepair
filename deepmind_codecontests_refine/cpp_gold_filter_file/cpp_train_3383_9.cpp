#include <bits/stdc++.h>
using namespace std;
const int maxn = 1180000;
bool isprm[maxn];
int prm[maxn];
void GetPrm(int n) {
  memset(isprm, 0, sizeof(isprm));
  for (long long i = 2; i <= n; ++i)
    if (!isprm[i]) {
      for (long long j = i * i; j <= n; j += i) isprm[j] = 1;
    }
  prm[0] = prm[1] = 0;
  for (int i = 2; i <= n; ++i) {
    isprm[i] ^= 1;
    prm[i] = prm[i - 1] + isprm[i];
  }
}
bool ispal[maxn];
int pal[maxn];
int buf[10];
bool judge(int num) {
  int idx = 0;
  while (num) {
    buf[idx++] = num % 10;
    num /= 10;
  }
  int L = 0, R = idx - 1;
  while (L < R) {
    if (buf[L] != buf[R]) return false;
    L++;
    R--;
  }
  return true;
}
void GetPal(int n) {
  for (int i = 1; i <= n; ++i) ispal[i] = judge(i);
  pal[0] = 0;
  for (int i = 1; i <= n; ++i) pal[i] = pal[i - 1] + ispal[i];
}
int p, q;
int main() {
  int n = 1179859;
  GetPrm(n);
  GetPal(n);
  scanf("%d %d", &p, &q);
  if (p < 0 || q < 0) {
    p = -p;
    q = -q;
  }
  int res = -1;
  for (int i = n; i >= 1; --i) {
    long long a = (long long)prm[i] * q;
    long long b = (long long)pal[i] * p;
    if (a <= b) {
      res = i;
      break;
    }
  }
  if (res == -1)
    puts("Palindromic tree is better than splay tree");
  else
    printf("%d\n", res);
  return 0;
}
