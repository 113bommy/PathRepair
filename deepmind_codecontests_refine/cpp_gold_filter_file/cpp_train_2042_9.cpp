#include <bits/stdc++.h>
int ___read_tmp;
using namespace std;
int h[2000001];
unsigned long long cnts[2000001];
unsigned long long hsum[2000001];
bool p[2000001];
int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  for (int i = (0); i < (n); i++) {
    int tmp;
    scanf("%d", &tmp);
    h[tmp]++;
  }
  for (int i = (1); i < (2000001); i++) {
    cnts[i] = cnts[i - 1] + h[i];
    hsum[i] = hsum[i - 1] + cnts[i];
  }
  int g_gain = x / y;
  unsigned long long yy = y, xx = x;
  unsigned long long mintotal = xx * (unsigned long long)n;
  for (int i = (2); i < (2000001); i++) {
    if (p[i]) continue;
    int gain = min(g_gain, i - 1);
    int used_cnt = 0;
    unsigned long long currtotal = 0;
    for (int j = i; j <= 2000000; j += i) {
      p[j] = true;
      used_cnt += cnts[j] - cnts[j - gain - 1];
      currtotal +=
          yy * (hsum[j - 1] - (hsum[j - gain - 1] + cnts[j - gain - 1] * gain));
    }
    currtotal += xx * (n - used_cnt);
    mintotal = min(mintotal, currtotal);
  }
  printf("%I64d", mintotal);
  return 0;
}
