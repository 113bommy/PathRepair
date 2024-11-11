#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int INF = 1e7;
const long long Mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= Mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % Mod;
    a = a * a % Mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
struct haha {
  int pos, dat;
} arr[maxn];
char st[maxn];
int sheng[maxn], xiao[2], k, res, arrnum;
int main() {
  scanf("%s", st);
  k = strlen(st);
  res = 0;
  for (int i = 0; i <= k - 1; i++) {
    if (st[i] == '1') {
      sheng[i] = 1 + max(xiao[1], xiao[0]);
      xiao[1] = sheng[i];
    } else {
      sheng[i] = ++xiao[0];
      res++;
    }
  }
  int qian[3] = {0};
  arrnum = 0;
  for (int i = 0; i <= k - 1; i++) {
    if (st[i] == '1') {
      qian[2] = sheng[i];
    } else {
      while (arrnum > 0 && arr[arrnum].dat >= qian[2] - sheng[i]) arrnum--;
      arrnum++;
      arr[arrnum].pos = i;
      arr[arrnum].dat = qian[2] - sheng[i];
    }
  }
  arrnum++;
  arr[arrnum].pos = k;
  arr[arrnum].dat = k * 2;
  int arrnow = 1;
  res = 0;
  for (int i = 0; i <= k - 1; i++)
    if (st[i] == '1') {
      if (qian[0] >= qian[1]) {
        qian[2] = sheng[i];
        bool boo = true;
        while (arrnow <= arrnum && arr[arrnow].pos < i) arrnow++;
        if (arrnow > arrnum)
          boo = false;
        else {
          if (res >= arr[arrnow].dat) boo = false;
        }
        if (boo) {
          st[i] = '0';
          res++;
          qian[0] = sheng[i];
        }
      }
      qian[1] = sheng[i];
    } else {
      qian[0] = sheng[i];
    }
  printf("%s", st);
  return 0;
}
