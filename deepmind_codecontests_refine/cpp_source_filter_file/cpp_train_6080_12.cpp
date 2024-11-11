#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, h;
double ans;
string s;
int main() {
  cin >> s;
  n = read();
  h = read();
  if (s == "Bob")
    printf("%d\n", n);
  else
    for (int i = 1; i <= h; i++)
      for (int j = 1; j <= n; j++)
        ans += (n - j) * (1 / pow(2, 2 * i)) * pow(1 - 1 / pow(2, i), j - 1) *
               (pow(2, i) - pow(2, i - 1) * (1 + (j - 1) / (pow(2, i) - 1)));
  printf("%.9lf", n + ans);
  return 0;
}
