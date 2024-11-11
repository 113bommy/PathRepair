#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 2e18;
const int N = 1231234;
int n, k;
char s[12];
int a[N];
int main() {
  while (cin >> n >> k) {
    int i, j;
    n++;
    int cnt = 0;
    for (i = 0; i < n; ++i) {
      scanf("%s", s);
      if (s[0] == '?') {
        a[i] = inf;
      } else {
        int o = 0;
        if (s[0] == '-') o = 1;
        int len = strlen(s);
        int num = 0;
        for (j = o; j < len; ++j) {
          num = num * 10 + s[j] - '0';
        }
        if (o) num *= -1;
        a[i] = num;
        cnt++;
      }
    }
    if (!k) {
      if (a[0] == 0 || a[0] == inf && (cnt & 1))
        puts("Yes");
      else
        puts("No");
    } else {
      if (cnt != n) {
        puts((n & 1) ? "No" : "Yes");
        continue;
      }
      long long ans = 0;
      for (i = n - 1; i >= 0; --i) {
        ans = k * ans + a[i];
        if (abs(ans) > 1e10) break;
      }
      if (ans == 0)
        puts("Yes");
      else
        puts("No");
    }
  }
}
