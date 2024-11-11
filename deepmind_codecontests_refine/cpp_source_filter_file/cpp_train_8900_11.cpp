#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 100000 + 5;
int main() {
  int n, i, s[M], sm[M], smm[M], cnt;
  while (~scanf("%d", &n)) {
    for (i = 1; i <= n; i++) scanf("%d", &s[i]);
    sm[1] = s[1];
    for (i = 2; i <= n; i++) sm[i] = max(sm[i - 1], s[i]);
    smm[n] = s[n];
    for (i = n - 1; i >= 1; i--) smm[i] = min(smm[i + 1], s[i]);
    cnt = 0;
    for (i = 1; i <= n; i++)
      if (sm[i] <= smm[i + 1]) cnt++;
    printf("%d\n", cnt + 1);
  }
  return 0;
}
