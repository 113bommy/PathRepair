#include <bits/stdc++.h>
using namespace std;
long long get() {
  char c = getchar();
  long long x = 0LL;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    x *= 10LL;
    x += (c - '0');
    c = getchar();
  }
  return x;
}
int t, a, b, c;
int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int mn = -1, aa, ab, ac;
    for (int i = 1; i < 20001; i++) {
      for (int j = i; j < 20001; j += i)
        for (int k = j; k < 20001; k += j) {
          if (mn == -1 || mn > (abs(a - i) + abs(b - j) + abs(c - k))) {
            aa = i;
            ab = j;
            ac = k;
            mn = (abs(a - i) + abs(b - j) + abs(c - k));
          }
        }
    }
    cout << mn << "\n" << aa << " " << ab << " " << ac << "\n";
  }
  return 0;
}
