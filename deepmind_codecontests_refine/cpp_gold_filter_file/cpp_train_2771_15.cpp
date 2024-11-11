#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2002;
int n, x[N], y[N];
int d[3000002];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    d[x[i]] = 1;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &y[i]);
    d[y[i]] = 1;
  }
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) res += d[x[i] ^ y[j]];
  res %= 2;
  if (res == 0)
    printf("Karen");
  else
    printf("Koyomi");
}
