#include <bits/stdc++.h>
using namespace std;
int a[10010];
struct node {
  int a, b, c;
} s[40010];
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    int sum = 0;
    int cnt = 0;
    int k;
    int flag = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    if (sum % n == 0)
      sum /= n;
    else {
      printf("-1\n");
      continue;
    }
    for (int i = 2; i <= n; i++) {
      if (a[i] % i == 0) {
        s[++cnt].a = i;
        s[cnt].b = 1;
        s[cnt].c = a[i] / i;
      } else {
        s[++cnt].a = 1;
        s[cnt].b = i;
        s[cnt].c = i - a[i] % i;
        s[++cnt].a = i;
        s[cnt].b = 1;
        s[cnt].c = a[i] / i + 1;
      }
    }
    for (int i = 2; i <= n; i++) {
      s[++cnt].a = 1;
      s[cnt].b = i;
      s[cnt].c = i;
    }
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
      printf("%d %d %d\n", s[i].a, s[i].b, s[i].c);
    }
  }
  return 0;
}
