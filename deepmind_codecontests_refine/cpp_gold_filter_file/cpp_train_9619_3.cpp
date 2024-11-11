#include <bits/stdc++.h>
using namespace std;
template <typename T>
void lmax(T& a, const T& b) {
  if (a < b) a = b;
}
template <typename T>
void lmin(T& a, const T& b) {
  if (a > b) a = b;
}
const int N = 1000000;
int step[10][N];
int to[10][N];
inline int max_digit(int x) {
  int ret = 0;
  while (x > 0) {
    lmax(ret, x % 10);
    x /= 10;
  }
  return ret;
}
void init() {
  for (int n = 1; n < N; ++n) {
    for (int i = 0; i < 10; ++i) {
      int d = max(i, max_digit(n));
      if (n - d < 0) {
        step[i][n] = 0;
        to[i][n] = n;
      } else {
        step[i][n] = step[i][n - d] + 1;
        to[i][n] = to[i][n - d];
      }
    }
  }
}
int main() {
  init();
  long long ans = 0;
  long long n;
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  int lf = n / N;
  int rt = n % N;
  while (lf >= 0) {
    if (lf == 0 and rt == 0) break;
    int md = max_digit(lf);
    ans += step[md][rt];
    rt = to[md][rt];
    if (lf == 0 and rt == 0) break;
    rt = rt + N - max(max_digit(rt), md);
    ++ans;
    --lf;
  }
  cout << ans;
  return 0;
}
