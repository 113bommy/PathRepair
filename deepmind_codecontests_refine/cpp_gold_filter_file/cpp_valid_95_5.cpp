#include <bits/stdc++.h>
using namespace std;
long long res[110];
int dig[11];
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    long long s, n;
    scanf("%lld%lld", &s, &n);
    int ndig = 0;
    int idx = 0;
    long long tem = s;
    long long b = 1;
    while (tem) {
      int cd = tem % 10;
      dig[idx++] = cd;
      tem /= 10;
      b *= 10;
    }
    b /= 10;
    int len = idx;
    idx = 0;
    long long rem = n;
    while (1) {
      while (rem > 1 && s - b >= rem - 1) {
        s -= b;
        res[idx++] = b;
        rem--;
        if (rem == 1) break;
      }
      if (rem == 1) {
        res[idx++] = s;
        rem--;
        break;
      }
      b /= 10;
    }
    for (int j = 0; j < idx; j++) {
      printf("%d", res[j]);
      if (j != idx - 1)
        printf(" ");
      else
        printf("\n");
    }
  }
  return 0;
}
