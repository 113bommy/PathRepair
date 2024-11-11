#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxm = 50005;
const int mod = 1e9 + 7;
int n, cnt;
long long anst, ansd;
int a[maxn], b[maxn], cur_a[maxn][maxm], cur_b[maxn][maxm], pri[maxm];
bool no[maxm];
vector<int> all;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b)
    x = 1, y = 0;
  else
    exgcd(b, a % b, y, x), y -= (a / b) * x;
}
void upd(long long &b, long long &a, long long d, long long c) {
  if (!c) {
    if (a && d >= b && (d - b) % a == 0)
      b = d, a = 0;
    else if (!a && d == b)
      b = d, a = 0;
    else {
      puts("-1");
      exit(0);
    }
    return;
  }
  long long g = gcd(a, c);
  if ((d - b) % g) {
    puts("-1");
    exit(0);
  }
  long long tmp_x, tmp_y;
  exgcd(a, c, tmp_x, tmp_y);
  tmp_x *= (d - b) / g;
  tmp_y *= (b - d) / g;
  if (tmp_x < 0 || tmp_y < 0) {
    long long cnt =
        max((-tmp_x + (c / g) - 1) / (c / g), (-tmp_y + (a / g) - 1) / (a / g));
    tmp_x += cnt * (c / g);
    tmp_y += cnt * (a / g);
  }
  long long cnt = min(tmp_x / (c / g), tmp_y / (a / g));
  tmp_x -= cnt * (c / g);
  tmp_y -= cnt * (a / g);
  a = (a * c) / g;
  b = tmp_y * c + d;
}
int power(int x, int pow) {
  int res = 1;
  for (; pow; pow >>= 1) {
    if (pow & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod;
  }
  return res;
}
void check(int i, long long t, long long d) {
  int pos = -1;
  for (int k = 0; k < (int(all.size())); k++) {
    if (!cur_b[1][k] && cur_a[i][k] + t * cur_b[i][k] != cur_a[1][k]) {
      puts("-1");
      exit(0);
    } else if (cur_b[1][k]) {
      if (cur_a[i][k] + t * cur_b[i][k] < cur_a[1][k] ||
          ((cur_a[i][k] + t * cur_b[i][k] - cur_a[1][k]) % cur_b[1][k])) {
        puts("-1");
        exit(0);
      }
      long long cur =
          (cur_a[i][k] + t * cur_b[i][k] - cur_a[1][k]) / cur_b[1][k];
      if (pos >= 0 && cur != pos) {
        puts("-1");
        exit(0);
      }
      pos = cur;
    }
  }
  upd(anst, ansd, pos, d);
}
int main() {
  anst = 0;
  ansd = 1;
  no[1] = true;
  for (int i = 2; i <= 50000; i++) {
    if (!no[i]) pri[++cnt] = i;
    for (int j = 1; j <= (cnt); j++) {
      if (i * pri[j] > 50000) break;
      no[i * pri[j]] = true;
      if (i % pri[j] == 0) break;
    }
  }
  scanf("%d", &n);
  for (int i = 1; i <= (n); i++) {
    scanf("%d%d", &a[i], &b[i]);
    int tmp_a = a[i], tmp_b = b[i];
    for (int j = 1; j <= (cnt); j++) {
      if (pri[j] * pri[j] > tmp_a) break;
      if (tmp_a % pri[j] == 0) all.push_back(pri[j]);
      while (tmp_a % pri[j] == 0) tmp_a /= pri[j];
    }
    if (tmp_a > 1) all.push_back(tmp_a);
    for (int j = 1; j <= (cnt); j++) {
      if (pri[j] * pri[j] > tmp_b) break;
      if (tmp_b % pri[j] == 0) all.push_back(pri[j]);
      while (tmp_b % pri[j] == 0) tmp_b /= pri[j];
    }
    if (tmp_b > 1) all.push_back(tmp_b);
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  for (int i = 1; i <= (n); i++) {
    for (int j = 0; j < (int(all.size())); j++) {
      int p = all[j];
      int tmp_a = a[i], tmp_b = b[i];
      while (tmp_a % p == 0) cur_a[i][j]++, tmp_a /= p;
      while (tmp_b % p == 0) cur_b[i][j]++, tmp_b /= p;
    }
  }
  for (int i = 2; i <= n; i++) {
    int j = 0;
    while (j < int(all.size()) && !cur_b[i][j]) j++;
    if (j == int(all.size()) || !cur_b[1][j])
      check(i, 0, 0);
    else {
      int k = 0;
      while (k < int(all.size()) &&
             cur_b[1][k] * cur_b[i][j] == cur_b[i][k] * cur_b[1][j])
        k++;
      if (k == int(all.size())) {
        long long g = gcd(cur_b[1][j], cur_b[i][j]);
        if ((cur_a[1][j] - cur_a[i][j]) % g) {
          puts("-1");
          return 0;
        }
        long long tmp_x, tmp_y;
        exgcd(cur_b[1][j], cur_b[i][j], tmp_x, tmp_y);
        tmp_x *= (cur_a[i][j] - cur_a[1][j]) / g;
        tmp_y *= (cur_a[1][j] - cur_a[i][j]) / g;
        if (tmp_x < 0 || tmp_y < 0) {
          long long cnt =
              max((-tmp_x + (cur_b[i][j] / g) - 1) / (cur_b[i][j] / g),
                  (-tmp_y + (cur_b[1][j] / g) - 1) / (cur_b[1][j] / g));
          tmp_x += cnt * (cur_b[i][j] / g);
          tmp_y += cnt * (cur_b[1][j] / g);
        }
        long long cnt =
            min(tmp_x / (cur_b[i][j] / g), tmp_y / (cur_b[1][j] / g));
        tmp_x -= cnt * (cur_b[i][j] / g);
        tmp_y -= cnt * (cur_b[1][j] / g);
        check(i, tmp_y, cur_b[i][j] / g);
      } else {
        long long tmp_x1 =
            1LL * cur_a[i][j] * cur_b[i][k] - 1LL * cur_a[1][j] * cur_b[i][k];
        long long tmp_x2 =
            1LL * cur_a[i][k] * cur_b[i][j] - 1LL * cur_a[1][k] * cur_b[i][j];
        if ((tmp_x1 - tmp_x2) % (1LL * cur_b[1][j] * cur_b[i][k] -
                                 1LL * cur_b[1][k] * cur_b[i][j])) {
          puts("-1");
          return 0;
        }
        long long tmp_x = (tmp_x1 - tmp_x2) / (1LL * cur_b[1][j] * cur_b[i][k] -
                                               1LL * cur_b[1][k] * cur_b[i][j]);
        long long tmp_y = tmp_x * cur_b[1][j] + cur_a[1][j] - cur_a[i][j];
        if (tmp_y % cur_b[i][j]) {
          puts("-1");
          return 0;
        }
        tmp_y /= cur_b[i][j];
        if (tmp_x < 0 || tmp_y < 0) {
          puts("-1");
          return 0;
        }
        check(i, tmp_y, 0);
      }
    }
  }
  printf("%d\n", 1LL * a[1] * power(b[1], int(anst % (mod - 1))) % mod);
  return 0;
}
