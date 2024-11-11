#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
bool ft = 0;
int n;
long long ans, c[N], f[N], w[N], sum[N], ch[N][2], op[N][2];
inline int read() {
  int num = 0;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  return num;
}
inline bool check(int u, int c) {
  long long s = f[c], ta = u / c + 1, t = (u * 2) / c + 1;
  if (op[t][0] >= u * 2 && s - op[t][0] / c + (op[t][0] - u * 2) / c >= u)
    return true;
  if (ch[t * c - 1][0] >= u * 2 &&
      s - ch[t * c - 1][0] / c + (ch[t * c - 1][0] - u * 2) / c >= u)
    return true;
  int a = op[ta][0], b = op[ta][1], k = 0;
  k = ch[ta * c - 1][0];
  if (k >= u) {
    if (k % c > a % c)
      b = a, a = k;
    else if (a == 0)
      a = k;
    else if (k % c > b % c)
      b = k;
    else if (b == 0)
      b = k;
  }
  k = ch[ta * c - 1][1];
  if (k >= u) {
    if (k % c > a % c)
      b = a, a = k;
    else if (a == 0)
      a = k;
    else if (k % c > b % c)
      b = k;
    else if (b == 0)
      b = k;
  }
  if (a >= u && b >= u && s - a / c - b / c + (a - u) / c + (b - u) / c >= u)
    return true;
  return false;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) w[read()]++;
  n = 5e5;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + w[i];
  for (int i = 1; i <= n; i++)
    for (int x = i; x <= n; x += i)
      f[i] += (x / i) * (sum[min(x + i - 1, n)] - sum[x - 1]);
  for (int i = 1; i <= n; i++) {
    if (w[i] >= 2)
      ch[i][0] = ch[i][1] = i;
    else if (w[i] == 1)
      ch[i][0] = i, ch[i][1] = ch[i - 1][0];
    else
      ch[i][0] = ch[i - 1][0], ch[i][1] = ch[i - 1][1];
  }
  for (int i = 2; i <= n; i++) {
    int l = 2, r = n;
    for (int x = 0; x * i <= n; x++) {
      op[x][0] = ch[min((x + 1) * i - 1, n)][0],
      op[x][1] = ch[min((x + 1) * i - 1, n)][1];
      if (op[x][0] < x * i) op[x][0] = 0;
      if (op[x][1] < x * i) op[x][1] = 0;
    }
    for (int x = n / i; x >= 0; x--) {
      int a = op[x + 1][0], b = op[x + 1][1];
      if (a % i > op[x][0] % i)
        op[x][1] = op[x][0], op[x][0] = a;
      else if (op[x][0] == 0)
        op[x][0] = a;
      else if (a % i > op[x][1] % i)
        op[x][1] = a;
      else if (op[x][1] == 0)
        op[x][1] = a;
      if (b % i > op[x][0] % i)
        op[x][1] = op[x][0], op[x][0] = b;
      else if (op[x][0] == 0)
        op[x][0] = b;
      else if (b % i > op[x][1] % i)
        op[x][1] = b;
      else if (op[x][1] == 0)
        op[x][1] = b;
    }
    long long pos = 0;
    while (l <= r) {
      int d = (l + r) >> 1;
      if (check(d, i))
        pos = d, l = d + 1;
      else
        r = d - 1;
    }
    ans = max(ans, pos * i);
    for (int x = n / i; x >= 0; x--) op[x][0] = op[x][1] = 0;
  }
  cout << ans << endl;
  return 0;
}
