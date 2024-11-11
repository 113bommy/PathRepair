#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const long long linf = 0x3f3f3f3f3f3f3f3f;
int a[maxn];
int t[maxn], op[maxn];
int q[maxn];
int h = 1, ta = 0;
long long mi[maxn];
int main() {
  long long n, a, b, c, d, st, len;
  cin >> n >> a >> b >> c >> d >> st >> len;
  for (int i = 1; i <= n; i++) scanf("%d%d", &t[i], &op[i]);
  long long gd = st;
  long long sum = 0;
  int j = 1;
  long long mi = linf;
  for (int i = 1; i <= n; i++) {
    while (j <= n && t[j] - t[i] < len) {
      sum += op[j] ? c : -d;
      ++j;
      mi = min(mi, sum);
    }
    if (gd + mi >= 0) {
      if (i == 1)
        cout << 0 << endl;
      else
        cout << t[i - 1] + 1, exit(0);
    }
    gd += op[i] ? a : -b;
    sum -= op[i] ? c : -d;
    mi -= op[i] ? c : -d;
    if (gd < 0) {
      printf("-1\n");
      exit(0);
    }
  }
  cout << t[n] + 1 << endl;
  return 0;
}
