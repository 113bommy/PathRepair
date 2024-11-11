#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
template <typename T, typename... Args>
void read(T &first, Args &...args) {
  read(first);
  read(args...);
}
template <typename T>
void write(T arg) {
  T x = arg;
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}
template <typename T, typename... Ts>
void write(T arg, Ts... args) {
  write(arg);
  if (sizeof...(args) != 0) {
    putchar(' ');
    write(args...);
  }
}
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int N = 2e5 + 5;
int n, d, m;
long long a[N];
long long x[N], y[N];
int tot1, tot2;
long long sum[N];
bool cmp(int x, int y) { return x > y; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> d >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > m)
      y[++tot2] = a[i];
    else
      x[++tot1] = a[i];
  }
  sort(x + 1, x + 1 + tot1, cmp);
  sort(y + 1, y + 1 + tot2, cmp);
  for (int i = 1; i <= tot1; i++) sum[i] = sum[i - 1] + x[i];
  long long now = 0, ans = sum[tot1];
  for (int i = 1; i <= tot2; i++) {
    now += y[i];
    int cur = (i - 1) * d - i;
    if (cur > n) break;
    int tmp = min(n - cur, tot1);
    ans = max(ans, sum[tmp] + now);
  }
  cout << ans << endl;
}
