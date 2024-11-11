#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int inf = 0x3f3f3f3f;
int a[maxn], cnt, n, k;
string s;
int main() {
  scanf("%d%d", &n, &k);
  n++;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s[0] == '?')
      a[i] = inf;
    else {
      int p = 0;
      if (s[0] == '-') p = 1;
      for (int j = p; j < s.size(); j++) a[i] = a[i] * 10 + (int)(s[j] - '0');
      if (s[0] == '-') a[i] = a[i] * (-1);
      cnt++;
    }
  }
  if (k == 0) {
    if (a[0] == inf) {
      if (cnt % 2 == 0)
        printf("YES\n");
      else
        printf("NO\n");
    } else if (a[0])
      printf("NO\n");
    else
      printf("YES\n");
  } else {
    if (cnt < n) {
      if (cnt % 2 == 0)
        printf("NO\n");
      else
        printf("YES\n");
    } else {
      long long now = 0;
      for (int i = n - 1; i >= 0 && abs(now) < 1e14; i--)
        now = 1LL * now * k + a[i];
      printf("%s\n", (now ? "No" : "Yes"));
    }
  }
}
