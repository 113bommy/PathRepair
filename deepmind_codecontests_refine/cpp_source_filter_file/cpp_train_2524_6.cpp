#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T>
inline void write(T x) {
  int i = 20;
  char buf[21];
  buf[20] = '\n';
  do {
    buf[--i] = x % 10 + '0';
    x /= 10;
  } while (x);
  do {
    putchar(buf[i]);
  } while (buf[i++] != '\n');
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, x, k, csum = 0;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
      cin >> x;
      arr.push_back(x);
      csum += x;
    }
    if (csum % k != 0) {
      cout << n << endl;
      continue;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] % k == 0) {
        cnt++;
      }
    }
    if (cnt == n) {
      cout << "-1\n";
      continue;
    }
    csum = 0;
    int lpos = -1, rpos = n;
    for (int i = 0; i < n; i++) {
      csum += arr[i];
      if (csum % k != 0) {
        lpos = i;
        break;
      }
    }
    csum = 0;
    for (int i = n - 1; i >= 0; i--) {
      csum += arr[i];
      if (csum % k != 0) {
        rpos = i;
        break;
      }
    }
    int ans = max(n - lpos - 1, n - (n - 1 - rpos));
    cout << ans << endl;
  }
  return 0;
}
