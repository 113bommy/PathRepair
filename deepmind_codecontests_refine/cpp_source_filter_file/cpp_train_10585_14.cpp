#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &res) {
  res = 0;
  char c = getchar();
  T f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    res = res * 10 + c - '0';
    c = getchar();
  }
  res *= f;
}
map<int, int> mm;
const long long mod = 1e9 + 7;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
long long getpow(long long a, long long b) {
  long long ans = 0;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
const int maxn = 1e5 + 5;
pair<int, int> pp[10];
long long ans[maxn];
int main() {
  int x = 100, y = 100, mx = -100, my = -100;
  int x1 = 100, y1 = 100, mx1 = -100, my1 = -100;
  for (int i = 1; i <= 8; i++) scanf("%d%d", &pp[i].first, &pp[i].second);
  for (int i = 1; i <= 4; i++) {
    x = min(pp[i].first, x);
    y = min(pp[i].second, y);
    mx = max(mx, pp[i].first);
    my = max(my, pp[i].second);
  }
  for (int i = 5; i <= 8; i++) {
    x1 = min(x1, pp[i].first);
    y1 = min(y1, pp[i].second);
    mx1 = max(mx1, pp[i].first);
    my1 = max(my1, pp[i].second);
  }
  if (x > mx1 || y > my1 || mx < x1 || my < y1) {
    printf("NO\n");
    return 0;
  }
  int xx = min(abs(x - mx1), abs(mx - x1));
  int yy = min(abs(y - my1), abs(my - y1));
  if ((xx + yy) * 2 < abs(mx1 - my1))
    printf("NO\n");
  else
    printf("YES\n");
}
