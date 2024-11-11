#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 1e3 + 10;
int n, k, now, ans[N], pos[2 * N];
pair<int, int> a[N], b[N];
bitset<2 * N> f[2 * N];
pair<int, int> get(int id) {
  int u = -1, v = -1;
  if (a[id].first >= 0) {
    if (b[id].first == a[id].first || b[id].second == a[id].first)
      ;
    else if (u == -1)
      u = a[id].first;
    else
      v = a[id].first;
  }
  if (a[id].second >= 0) {
    if (b[id].first == a[id].second || b[id].second == a[id].second)
      ;
    else if (u == -1)
      u = a[id].second;
    else
      v = a[id].second;
  }
  if (b[id].first >= 0) {
    if (a[id].first == b[id].first || a[id].second == b[id].first)
      ;
    else if (u == -1)
      u = b[id].first;
    else
      v = b[id].first;
  }
  if (b[id].second >= 0) {
    if (a[id].first == b[id].second || a[id].second == b[id].second)
      ;
    else if (u == -1)
      u = b[id].second;
    else
      v = b[id].second;
  }
  return pair<int, int>(u, v);
}
void Gauss() {
  int r = 0;
  for (int i = 0; i <= 2 * n - 1; ++i) {
    int p = r;
    while (!f[p][i] && p < now) ++p;
    if (p == now) continue;
    if (p != r) swap(f[p], f[r]);
    for (int j = 0; j <= now - 1; ++j)
      if (j != r && f[j][i]) f[j] ^= f[r];
    pos[r++] = i;
  }
  for (int i = r; i <= now - 1; ++i)
    if (f[i][2 * n]) puts("NO"), exit(0);
  for (int i = 0; i <= r - 1; ++i)
    if (f[i][2 * n]) {
      if (pos[i] < n)
        ans[pos[i]] ^= 1;
      else
        ans[pos[i] - n] ^= 2;
    }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n - 1; ++i) a[i] = pair<int, int>(i, -1);
  for (int i = 0; i <= n - 1; ++i) b[i] = pair<int, int>(i + n, -1);
  for (int i = 1; i <= k; ++i) {
    char op[10], c;
    int t, first;
    scanf("%s%d", op, &t);
    if (op[0] == 'm') {
      for (int j = 1; j <= t; ++j) {
        scanf("%d", &first), --first;
        if (a[first].first >= 0) f[now][a[first].first] = 1;
        if (a[first].second >= 0) f[now][a[first].second] = 1;
        if (b[first].first >= 0) f[now + 1][b[first].first] = 1;
        if (b[first].second >= 0) f[now + 1][b[first].second] = 1;
      }
      scanf(" %c", &c);
      if (c == 'R')
        f[now][2 * n] = 1;
      else if (c == 'Y')
        f[now + 1][2 * n] = 1;
      else if (c == 'B')
        f[now][2 * n] = f[now + 1][2 * n] = 1;
      now += 2;
    } else if (op[0] == 'R' && op[1] == 'B') {
      for (int j = 1; j <= t; ++j) {
        scanf("%d", &first), --first;
        b[first] = get(first);
      }
    } else if (op[0] == 'R' && op[1] == 'Y') {
      for (int j = 1; j <= t; ++j) {
        scanf("%d", &first), --first;
        swap(a[first], b[first]);
      }
    } else {
      for (int j = 1; j <= t; ++j) {
        scanf("%d", &first), --first;
        a[first] = get(first);
      }
    }
  }
  Gauss();
  puts("YES");
  for (int i = 0; i <= n - 1; ++i) printf("%c", ".RYB"[ans[i]]);
  putchar(10);
}
