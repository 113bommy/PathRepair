#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
bool checkBit(int n, int i) { return (n & (1 << i)); }
int setBit(int n, int i) { return (n | (1 << i)); }
int resetBit(int n, int i) { return (n & (~(1 << i))); }
bool odd(long long n) { return (n & 1); }
int a[1010][1010];
int main() {
  int n, p, q;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &p, &q);
    --p, --q;
    a[p][q] = 1;
  }
  long long ans = 0;
  for (int j = 0; j < 1000; ++j) {
    int i = 0, x = 0, cnt = 0;
    while (i + x < 1000 && j + x < 1000) cnt += a[i + x][j + x], ++x;
    ans += ((long long)cnt * (cnt - 1)) / 2;
  }
  for (int i = 1; i < 1000; ++i) {
    int j = 0, x = 0, cnt = 0;
    while (i + x < 1000 && j + x < 1000) cnt += a[i + x][j + x], ++x;
    ans += ((long long)cnt * (cnt - 1)) / 2;
  }
  for (int j = 0; j < 1000; ++j) {
    int i = 0, x = 0, cnt = 0;
    while (i + x < 1000 && j - x >= 0) cnt += a[i + x][j - x], ++x;
    ans += ((long long)cnt * (cnt - 1)) / 2;
  }
  for (int i = 1; i < 1000; ++i) {
    int j = 999, x = 0, cnt = 0;
    while (i + x < 1000 && j - x >= 0) cnt += a[i + x][j - x], ++x;
    ans += ((long long)cnt * (cnt - 1)) / 2;
  }
  cout << ans << endl;
  return 0;
}
