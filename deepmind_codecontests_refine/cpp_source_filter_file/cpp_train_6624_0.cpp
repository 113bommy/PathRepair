#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, P = 10, mod = 1e9 + 7;
int n, T;
char s[N];
long long p[N], h[N];
long long get(int l, int r) {
  long long res = (h[r] - h[l - 1] * p[r - l + 1]) % mod;
  if (res < 0) res += mod;
  return res;
}
void print(int la, int lb) {
  for (int i = 1; i <= la; i++) printf("%c", s[i]);
  printf("+");
  for (int i = la + 1; i <= la + lb; i++) printf("%c", s[i]);
  printf("=");
  for (int i = la + lb + 1; i <= n; i++) printf("%c", s[i]);
  printf("\n");
}
bool check(int la, int lb) {
  if (la <= 0 || lb <= 0) return false;
  if (lb != 1 && s[la + 1] == '0') return false;
  long long a = get(1, la);
  long long b = get(la + 1, la + lb);
  long long c = get(la + lb + 1, n);
  if (a + b == c) {
    print(la, lb);
    return true;
  }
  return false;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = (p[i - 1] * P) % mod;
    h[i] = (h[i - 1] * P + (s[i] - '0')) % mod;
  }
  for (int i = n / 2; i <= n; i++) {
    if (s[i] == '0' && i != n) continue;
    int lc = n - i + 1;
    if (check(lc, n - 2 * lc)) break;
    if (check(lc - 1, n - 2 * lc + 1)) break;
    if (check(n - 2 * lc, lc)) break;
    if (check(n - 2 * lc + 1, lc - 1)) break;
  }
  return 0;
}
