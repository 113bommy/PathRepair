#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, m, a[N], x, y, s[N], num[N];
int Calc(int i, int j) { return abs(a[i] - a[j]); }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  while (m--) {
    scanf("%d%d", &x, &y);
    long long res = 0, sum = 0;
    int t = 0;
    for (int i = x + 1; i <= y; i++) {
      int p = Calc(i - 1, i);
      sum += p;
      if (t == 0) {
        s[t] = p, num[t++] = 1;
      } else {
        int newnum = 1;
        while (t && p >= s[t - 1]) {
          t--;
          sum += 1LL * (p - s[t]) * num[t];
          newnum += num[t];
        }
        s[t] = p, num[t++] = newnum;
      }
      res += sum;
    }
    printf("%I64d\n", res);
  }
}
