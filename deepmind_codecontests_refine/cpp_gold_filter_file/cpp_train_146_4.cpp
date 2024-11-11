#include <bits/stdc++.h>
using namespace std;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const long long MOD = 1000000007;
template <typename T>
inline T Bigmod(T base, T power, T MOD) {
  T ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    int hun = 0, th = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x == 100)
        hun++;
      else
        th++;
    }
    int sum = hun * 100 + th * 200;
    if (sum % 200 != 0) {
      cout << "NO\n";
    } else {
      int h = sum / 2;
      bool ans = 0;
      for (int i = 0; i <= th; i++) {
        if (i * 200 <= h && h - i * 200 <= hun * 100) ans = 1;
      }
      if (ans)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
