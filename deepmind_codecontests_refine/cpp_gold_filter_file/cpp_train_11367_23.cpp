#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535897932384626433832795;
const long long INF = 1LL << 62;
const long long MINF = -1LL << 62;
template <typename T>
T getint() {
  T val = 0;
  char c;
  bool neg = false;
  while ((c = getchar()) && !(c >= '0' && c <= '9')) {
    neg |= c == '-';
  }
  do {
    val = (val * 10) + c - '0';
  } while ((c = getchar()) && (c >= '0' && c <= '9'));
  return val * (neg ? -1 : 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long x;
    cin >> x;
    long long hatv = 9;
    long long big_len = 0;
    long long small_len = 1;
    x--;
    while (1) {
      long long y = 0;
      for (long long z = 30; z >= 0; z--) {
        long long c = y + (1LL << z);
        if (c <= hatv && (x - big_len * c - small_len * (c * (c + 1)) / 2) >= 0)
          y = c;
      }
      if (y != hatv) {
        x -= big_len * y + small_len * (y * (y + 1)) / 2;
        long long pre = 0, num = 0, ennyi = 0;
        for (long long i = 9, j = 1, k = 1;; i *= 10, j++, k *= 10) {
          pre += i * j;
          if (pre >= x) {
            pre -= i * j;
            num = k + (x - pre) / j;
            ennyi = (x - pre) % j;
            break;
          }
        }
        vector<int> jegyek;
        while (num > 0) {
          jegyek.push_back(num % 10);
          num /= 10;
        }
        reverse((jegyek).begin(), (jegyek).end());
        cout << jegyek[ennyi] << "\n";
        break;
      }
      x -= big_len * hatv + small_len * (hatv * (hatv + 1)) / 2;
      big_len += small_len * hatv;
      hatv *= 10;
      small_len++;
    }
  }
  return 0;
}
