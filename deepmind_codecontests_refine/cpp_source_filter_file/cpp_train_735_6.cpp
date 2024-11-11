#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
long long C(int a, int b) {
  long long ret = 1;
  for (int i = 1; i <= b; i++) ret *= (a - i + 1);
  for (int i = 1; i <= b; i++) ret /= i;
  return ret;
}
bool check(int a, int b, int c) {
  if ((a & 1) && (b & 2) && (c & 4)) return true;
  if ((a & 1) && (b & 4) && (c & 2)) return true;
  if ((a & 2) && (b & 1) && (c & 4)) return true;
  if ((a & 2) && (b & 4) && (c & 1)) return true;
  if ((a & 4) && (b & 1) && (c & 2)) return true;
  if ((a & 4) && (b & 2) && (c & 1)) return true;
  return false;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int fac[MAXN];
int main() {
  for (int i = 1; i < MAXN; i++)
    for (int j = i; j < MAXN; j += i) fac[j]++;
  int t;
  int x, y, z;
  int cnt[8], used[8];
  cin >> t;
  while (t--) {
    cin >> x >> y >> z;
    cnt[7] = fac[gcd(gcd(x, y), z)];
    cnt[6] = fac[gcd(x, y)] - cnt[7];
    cnt[5] = fac[gcd(x, z)] - cnt[7];
    cnt[3] = fac[gcd(y, z)] - cnt[7];
    cnt[4] = fac[x] - cnt[6] - cnt[5] - cnt[7];
    cnt[2] = fac[y] - cnt[6] - cnt[4] - cnt[7];
    cnt[1] = fac[z] - cnt[5] - cnt[4] - cnt[7];
    long long ans = 0;
    for (int i = 1; i < 8; i++) {
      for (int j = i; j < 8; j++) {
        for (int k = j; k < 8; k++) {
          if (check(i, j, k)) {
            memset(used, 0, sizeof(used));
            used[i]++;
            used[j]++;
            used[k]++;
            long long tmp = 1;
            for (int l = 1; l < 8; l++) {
              if (used[l]) tmp *= C(used[l] + cnt[l] - 1, used[l]);
            }
            if (tmp > 0) ans += tmp;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
