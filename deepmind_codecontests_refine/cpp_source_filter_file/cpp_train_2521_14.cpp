#include <bits/stdc++.h>
using namespace std;
template <class T>
bool up_max(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
bool up_min(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
const int mod = 1000000007;
int c[1005][1005];
void Init() {
  for (int i = 0; i <= 1000; ++i) c[i][0] = c[i][i] = 1;
  for (int i = 1; i <= 1000; ++i)
    for (int j = 1; j < i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}
int main() {
  Init();
  int n, m, k;
  while (cin >> n >> m >> k) {
    if (n - 1 < 2 * k || m - 1 < 2 * k) {
      puts("0");
      continue;
    } else
      cout << (c[n - 1][2 * k] * c[m - 1][2 * k]) % mod << endl;
  }
}
