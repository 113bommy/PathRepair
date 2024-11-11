#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int maxm = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int maxblock = sqrt(maxn) + 10;
const double eps = 1e-7;
const long long INF = 1e16;
int n;
int a[maxn], b[maxn];
int c[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d", &p);
    a[p] = i;
  }
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d", &p);
    b[p] = i;
  }
  for (int i = 1; i <= n; i++) {
    int diff = b[i] - a[i];
    if (diff < 0) diff += n;
    c[diff]++;
  }
  int Max = 0;
  for (int i = 1; i <= n; i++) Max = max(Max, c[i]);
  printf("%d\n", Max);
  return 0;
}
