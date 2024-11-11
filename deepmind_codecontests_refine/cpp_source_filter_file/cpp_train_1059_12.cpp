#include <bits/stdc++.h>
using namespace std;
long long sum[50000], l[50000];
long long len(int i) {
  int re = 0;
  while (i) {
    re++;
    i /= 10;
  }
  return re;
}
long long n, k = 1, t;
char z[5000100];
void strint(long long n, char re[]) {
  int le = 0;
  char te[6];
  while (n) {
    te[le++] = n % 10;
    n /= 10;
  }
  for (int i = 0; i < le; i++) re[i] = te[le - i - 1] + '0';
  k += le;
}
int main() {
  for (int i = 1; i <= 50000; i++) {
    l[i] = l[i - 1] + len(i);
    sum[i] = sum[i - 1] + l[i];
  }
  int num = 1;
  while (k < 5000000) {
    strint(num, z + k);
    num++;
  }
  z[1] = '1';
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &t);
    int l = 0, r = 50000;
    while (l < r - 1) {
      if (sum[((l + r) / 2)] < t)
        l = ((l + r) / 2);
      else
        r = ((l + r) / 2);
    }
    t -= sum[l];
    printf("%c\n", z[t]);
  }
  return 0;
}
