#include <bits/stdc++.h>
using namespace std;
const int N = 4e5;
const int mod = 1000000007;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-8;
struct unionset {
  int fat[1003], len;
  void init(int x) {
    len = x;
    for (int i = 0; i < x; i++) fat[i] = i;
    return;
  }
  int getf(int x) {
    if (fat[x] == x) return x;
    return fat[x] = getf(fat[x]);
  }
  void un(int x, int y) {
    fat[getf(y)] = getf(x);
    return;
  }
};
struct tree_array {
  int c[1003];
  int v[1003], len;
  int get_low(int x) { return x & (-x); }
  void init(int x) {
    len = x;
    for (int i = 0; i < x; i++) c[i] = v[i] = 0;
    return;
  }
  void add(int x, int value) {
    v[x] += value;
    while (x <= len) {
      c[x] += value;
      x += get_low(x);
    }
    return;
  }
  int sum(int x) {
    int ans = 0;
    while (x > 0) {
      ans += c[x];
      x -= get_low(x);
    }
    return ans;
  }
};
int pow_mod(int a, int b, int c) {
  long long ans = 1, tmp = a;
  while (b) {
    if (b & 1) ans = ans * tmp % c;
    tmp = tmp * tmp % c;
    b >>= 1;
  }
  return ans;
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
class ColorfulCoins {
 public:
  int minQueries(vector<long long> values) {
    int xx[100];
    int n = values.size() - 1;
    for (int i = 0; i < values.size(); i++) xx[i] = values[i + 1] / values[i];
    if (n == 0) return 0;
    int cnt = n, tag[100] = {0};
    while (cnt > 0) {
      int id = 0, bb = 0;
      for (int i = 0; i < n; i++)
        if (tag[i] == 0 && xx[i] > bb) {
          id = i;
          bb = xx[i];
        }
      tag[id] = 1;
      cnt--;
    }
  }
};
int num[403][403];
short l[403][403][403];
short a[160003];
short b[160003];
int main() {
  int i, j, n, m, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%d", &num[i][j]);
  memset(a, -1, sizeof(a));
  memset(b, -1, sizeof(b));
  memset(l, -1, sizeof(l));
  for (i = 0; i < n; i++)
    for (j = 0; j < n && j + i < n; j++) {
      for (k = 0; k < m; k++) {
        if (i > 0) l[j][i][k] = max(l[j][i - 1][k], l[j + 1][i - 1][k]);
        short tmp = b[num[j][k]];
        a[num[j][k]] = j;
        if (i != 0) tmp = max(tmp, a[num[i + j][k]]);
        l[j][i][k] = max(tmp, l[j][i][k]);
        b[num[i + j][k]] = j;
      }
      for (k = 0; k < m; k++) a[num[j][k]] = b[num[i + j][k]] = -1;
    }
  int ans = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < n && j + i < n; j++) {
      int r = 0;
      k = 0;
      while (k < m) {
        while (r < m) {
          if (l[j][i][r] < k)
            r++;
          else
            break;
        }
        ans = max((r - k) * (i + 1), ans);
        k++;
        r = max(k, r);
      }
    }
  printf("%d\n", ans);
  return 0;
}
