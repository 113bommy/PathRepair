#include <bits/stdc++.h>
using namespace std;
namespace mine {
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3fll;
long long qread() {
  long long ans = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' or c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c and c <= '9') ans = ans * 10 + c - '0', c = getchar();
  return ans * f;
}
void write(long long num) {
  if (num < 0) {
    num = -num;
    putchar('-');
  }
  if (num > 9) write(num / 10);
  putchar('0' + num % 10);
}
void write1(long long num) {
  write(num);
  putchar(' ');
}
void write2(long long num) {
  write(num);
  puts("");
}
void chmax(int &x, const int y) { x = x > y ? x : y; }
void chmin(long long &x, const int y) { x = x < y ? x : y; }
const int MAX_N = 3e5 + 10;
const long long MOD = 1e9 + 7;
void add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  if (x < 0) x += MOD;
}
int t0[MAX_N], t1[MAX_N], a[MAX_N], sum[MAX_N];
void main() {
  int n = qread();
  t0[0] = 1;
  for (int i = 1; i <= n; i++) {
    int num = qread();
    for (int j = 0; j <= 62; j++)
      if (num & (1ll << j)) a[i]++;
    sum[i] = sum[i - 1] + a[i];
    t0[i] = t0[i - 1] + ((sum[i] & 1) == 0);
    t1[i] = t1[i - 1] + (sum[i] & 1);
  }
  long long ans = 0;
  for (int r = 2; r <= n; r++) {
    int mx = a[r];
    for (int l = r - 1; l >= r - 150 and l >= 1; l--) {
      chmax(mx, a[l]);
      if (2 * mx <= sum[r] - sum[l - 1] and (sum[r] - sum[l - 1]) % 2 == 0)
        ans++;
    }
    if (r - 152 >= 0) {
      if (sum[r] & 1)
        ans += t1[r - 152];
      else
        ans += t0[r - 152];
    }
  }
  write(ans);
}
};  // namespace mine
int main() {
  srand(time(0));
  mine::main();
}
