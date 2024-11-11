#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 10;
const long long inf = 1ll << 60;
const long long mod = 1e9 + 7;
void GG() {
  cout << "0\n";
  exit(0);
}
long long mpow(long long a, long long n, long long mo = mod) {
  long long re = 1;
  while (n > 0) {
    if (n & 1) re = re * a % mo;
    a = a * a % mo;
    n >>= 1;
  }
  return re;
}
long long inv(long long b, long long mo = mod) {
  if (b == 1) return b;
  return (mo - mo / b) * inv(mo % b, mo) % mo;
}
const int maxn = 1e5 + 5;
int l[17][2 * 3 * maxn], r[17][2 * 3 * maxn];
int a[maxn];
void build(int k) {
  for (int o = 3 * maxn - 1; o > 0; --o) {
    l[k][o] = min(l[k][o * 2], l[k][o * 2 + 1]);
    r[k][o] = max(r[k][o * 2], r[k][o * 2 + 1]);
  }
}
pair<int, int> query(int L, int R, int k) {
  pair<int, int> re = {1000000000, -1};
  for (L += 3 * maxn, R += 3 * maxn; L < R; L >>= 1, R >>= 1) {
    if (L & 1) {
      re.second = max(re.second, (__typeof__(re.second))(r[k][L]));
      re.first = min(re.first, (__typeof__(re.first))(l[k][L]));
      ++L;
    }
    if (R & 1) {
      --R;
      re.second = max(re.second, (__typeof__(re.second))(r[k][R]));
      re.first = min(re.first, (__typeof__(re.first))(l[k][R]));
    }
  }
  return re;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < 3; ++j)
      l[0][i + j * n + 3 * maxn] = max(0, i + j * n - a[i]);
    for (int j = 0; j < 3; ++j)
      r[0][i + j * n + 3 * maxn] = min(3 * n - 1, i + j * n + a[i]);
  }
  build(0);
  for (int j = 1; j < 17; ++j) {
    for (int i = 0; i < 3 * n; ++i) {
      tie(l[j][i + 3 * maxn], r[j][i + 3 * maxn]) =
          query(l[j - 1][i + 3 * maxn], r[j - 1][i + 3 * maxn] + 1, j - 1);
    }
    build(j);
  }
  for (int i = 0; i < n; ++i) {
    int re = 0;
    int L = i + n, R = i + n;
    for (int j = 16; j >= 0; --j) {
      pair<int, int> np = query(L, R + 1, j);
      if (np.second - np.first < n - 1) {
        tie(L, R) = np;
        re += 1 << j;
      }
    }
    cout << re + 1 << ' ';
  }
}
