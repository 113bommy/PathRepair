#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
const int INF = 1e9 + 7;
const int MAXN = int(3e5 + 7);
int n, k;
double ans, a[1007], d[1007][1007];
string conv(long long x) {
  string second;
  while (x) second.push_back(x % 10 + '0'), x /= 10;
  reverse(second.begin(), second.end());
  return second;
}
long long pow(int x, int l) {
  long long res = 1;
  for (int i = 0; i < l; i++) res *= x;
  return res;
}
double calc(long long l, long long r) {
  long long res = 0;
  string t1 = conv(l), t2 = conv(r);
  long long t3 = pow(10, t1.size() - 1), t4 = pow(10, t2.size() - 1);
  if (t1.size() < t2.size()) {
    int lenl = t1.size(), lenr = t2.size();
    while (lenl != lenr - 1) res += pow(10, lenl++);
    if (t1[0] == '1') res += t3 * 2 - l;
    if (t2[0] == '1')
      res += r - t4 + 1;
    else
      res += t4;
  } else {
    if (t1[0] == '1') {
      if (t2[0] == '1')
        res += r - l + 1;
      else
        res += t3 * 2 - l;
    }
  }
  return (double)res / (r - l + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long l, r;
    scanf("%I64d%I64d", &l, &r);
    a[i] = calc(l, r);
  }
  scanf("%d", &k);
  d[0][0] = 1.0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) {
      d[i + 1][j + 1] += d[i][j] * a[i];
      d[i + 1][j] += d[i][j] * (1.0 - a[i]);
    }
  if ((n * k) % 100 == 0)
    k = n * k / 100;
  else
    k = n * k / 100 + 1;
  for (int i = k; i <= n; i++) ans += d[n][i];
  printf("%.10f", ans);
  return 0;
}
