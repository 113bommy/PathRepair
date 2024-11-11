#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int maxm = 150005;
const int mod = 100000000;
int n, m;
int a[maxn];
int o[maxn], t[maxn];
void init() {
  int oo = 0, tt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1)
      oo++;
    else
      tt++;
    o[i] = oo;
    t[i] = tt;
  }
  t[n + 1] = t[n];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  init();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int aaa = 0;
    for (int j = i; j <= n; j++) {
      aaa = max(aaa, o[j] - o[i - 1] + t[n] - t[j]);
    }
    int bbb = 0;
    for (int j = 1; j <= i; j++) {
      bbb = max(bbb, o[j - 1] + t[i - 1] - t[j - 1]);
    }
    ans = max(ans, aaa + bbb);
  }
  printf("%d\n", ans);
  return 0;
}
