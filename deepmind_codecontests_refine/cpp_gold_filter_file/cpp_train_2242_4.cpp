#include <bits/stdc++.h>
using namespace std;
double esp = 1e-11;
const double PI = acos(-1.0);
const long long int INF = 0x3f3f3f3f3f3f3f3f;
const long long int MOD = 1000000007ll;
const int maxn = 100010;
int k[maxn], m[maxn];
char s[maxn];
int main() {
  int n;
  scanf("%d%s", &n, s + 1);
  for (int x = 1; x <= n; x++) scanf("%d", &m[x]);
  int p = 1, t = 1;
  memset(k, 0, sizeof(k));
  int f = 1;
  while (k[p] == 0) {
    k[p] = t;
    t++;
    if (s[p] == '>')
      p += m[p];
    else
      p -= m[p];
    if (p < 1 || p > n) {
      f = 0;
      break;
    }
  }
  if (f == 0)
    printf("FINITE\n");
  else
    printf("INFINITE\n");
  return 0;
}
