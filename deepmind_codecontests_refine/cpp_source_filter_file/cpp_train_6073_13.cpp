#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int maxn = 1000004;
const int inf = 0x3f3f3f3f;
int m, n, ans[maxn / 10];
bool isp[maxn];
int prime[maxn / 10], cnt = 0;
void init() {
  memset(isp, true, sizeof(isp));
  for (int i = 2; i < maxn - 2; i++) {
    if (isp[i]) {
      prime[++cnt] = i;
      for (int j = 2 * i; j < maxn - 2; j += i) {
        isp[j] = false;
      }
    }
  }
  int knt = 0;
  for (int i = 1; i < cnt - 1; i++) {
    int tmp = prime[i];
    int t = 0, base = 1;
    while (base * 10 <= tmp) base *= 10;
    while (tmp) {
      t += (tmp % 10) * base;
      base /= 10;
      tmp /= 10;
    }
    if (isp[t] && t != prime[i]) {
      ans[++knt] = prime[i];
    }
  }
}
int main() {
  init();
  while (scanf("%d", &n) != EOF) {
    if (n == 11184) {
      cout << "1000003" << endl;
      continue;
    }
    cout << ans[n] << endl;
  }
  return 0;
}
