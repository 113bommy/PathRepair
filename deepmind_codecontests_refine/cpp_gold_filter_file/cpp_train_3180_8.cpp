#include <bits/stdc++.h>
using namespace std;
struct __s {
  __s() {
    srand(time(NULL));
    if (1) {
      ios_base::Init i;
      cin.sync_with_stdio(0);
      cin.tie(0);
    }
  }
  ~__s() {
    if (!1)
      fprintf(stderr, "Execution time: %.3lf s.\n",
              (double)clock() / CLOCKS_PER_SEC);
    long long n;
    cin >> n;
  }
} __S;
long long st = 1000;
long long mod = 1000000007;
long long n;
string s[1111];
long long d[8][2] = {{-1, 0},  {0, -1}, {1, 0},  {0, 1},
                     {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
long long b[2][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}};
int r[8][1111][1111];
int cnt[8][1111][1111][4];
pair<long long, long long> B[4][2222];
bool check(long long x) { return (0 <= x && x < n); }
bool check(long long x, long long y) { return check(x) && check(y); }
long long getSum(long long i, long long xl, long long yl, long long xr,
                 long long yr, long long a) {
  long long res = cnt[i][xl][yl][a];
  if (check(xr, yr)) res -= cnt[i][xr][yr][a];
  return res;
}
void get(long long x, long long y, long long i, long long rad, long long &a2,
         long long &a3) {
  for (long long j = 0; j < (long long)(4); j++) {
    long long xx = x + d[b[i][j]][0] * rad;
    long long yy = y + d[b[i][j]][1] * rad;
    a2 += getSum(b[i][j], x, y, xx, yy, 2);
    a3 += getSum(b[i][j], x, y, xx, yy, 3);
  }
  if (s[x][y] == '2') a2 -= 3;
  if (s[x][y] == '3') a3 -= 3;
}
pair<long long, long long> mul(long long a2, long long a3) {
  if (a2 == -1 || a3 == -1) return make_pair(0, 0);
  long long x = B[2][a2].first + B[3][a3].first;
  long long y = B[2][a2].second * B[3][a3].second;
  while (y > mod) {
    y /= st;
    x++;
  }
  return make_pair(x, y);
}
int main(void) {
  for (long long k = 2; k <= 3; k++) {
    B[k][0] = make_pair(0, 1);
    for (long long i = 1; i < 2222; i++) {
      B[k][i] = B[k][i - 1];
      B[k][i].second *= k;
      if (B[k][i].second > mod) {
        B[k][i].second /= st;
        B[k][i].first++;
      }
    }
  }
  cin >> n;
  for (long long i = 0; i < (long long)(n); i++) {
    cin >> s[i];
  }
  for (long long i = 0; i < (long long)(8); i++) {
    long long lx = 0, rx = n - 1, dx = 1;
    if (d[i][0] >= 0) {
      swap(lx, rx);
      dx *= -1;
    }
    long long ly = 0, ry = n - 1, dy = 1;
    if (d[i][1] >= 0) {
      swap(ly, ry);
      dy *= -1;
    }
    for (long long x = lx; check(x); x += dx) {
      for (long long y = ly; check(y); y += dy) {
        long long xx = x + d[i][0];
        long long yy = y + d[i][1];
        if (!check(xx, yy)) {
          r[i][x][y] = (s[x][y] != '0');
          cnt[i][x][y][s[x][y] - '0']++;
          continue;
        }
        for (long long j = 0; j < (long long)(4); j++) {
          cnt[i][x][y][j] = cnt[i][xx][yy][j];
        }
        cnt[i][x][y][s[x][y] - '0']++;
        if (s[x][y] == '0')
          r[i][x][y] = 0;
        else
          r[i][x][y] = r[i][xx][yy] + 1;
      }
    }
  }
  long long first = -1, second = -1, R = -1, I = -1;
  long long A2 = -1, A3 = -1;
  for (long long x = 0; x < (long long)(n); x++) {
    for (long long y = 0; y < (long long)(n); y++) {
      if (s[x][y] == '0') continue;
      for (long long i = 0; i < (long long)(2); i++) {
        int rad = n;
        for (long long j = 0; j < (long long)(4); j++) {
          rad = min(rad, r[b[i][j]][x][y]);
        }
        long long a2 = 0, a3 = 0;
        get(x, y, i, rad, a2, a3);
        if (mul(a2, a3) > mul(A2, A3)) {
          first = x;
          second = y;
          I = i;
          R = rad;
          A2 = a2;
          A3 = a3;
        }
      }
    }
  }
  if (R == -1) {
    cout << 0 << '\n';
    return 0;
  }
  long long sum = 1LL;
  for (long long i = 0; i < (long long)(A2); i++) {
    sum *= 2;
    sum %= mod;
  }
  for (long long i = 0; i < (long long)(A3); i++) {
    sum *= 3;
    sum %= mod;
  }
  cout << sum << '\n';
  return 0;
}
