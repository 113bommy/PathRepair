#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long f = 1, x = 0;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
int k, n = 2000, a[2003], S;
int main() {
  k = read();
  S = k + n - 1;
  a[1] = -1;
  S++;
  for (int i = 2; i <= n; ++i) a[i] = 1, S--;
  for (int i = 2; i <= n; ++i) {
    int tmp = min(1000000 - 1, S);
    a[2] += tmp;
    S -= tmp;
  }
  cout << n << '\n';
  for (int i = 1; i <= n; ++i) cout << a[i] << " ";
  return 0;
}
