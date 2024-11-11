#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && (c != '-'))
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
template <typename T>
inline void writep(T x) {
  if (x > 9) writep(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  writep(x);
}
template <typename T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
int n, a[100003 << 1];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int i, j, t, d;
  long long sum1 = 0, sum2 = 0;
  cin >> n;
  a[1] = 1, a[n + 1] = 2;
  for (i = 2; i < n + 1; i += 2) a[i] = 2 * n - i + 2;
  for (i = 3; i < n + 1; i += 2) a[i] = i;
  for (i = n + 1; i <= 2 * n; i += 2) a[i] = a[i - n] + 1;
  for (i = n + 2; i <= 2 * n; i += 2) a[i] = a[i - n] - 1;
  for (i = 1; i <= n; i++) sum1 += a[i];
  sum2 = 1;
  for (i = n + 2; i <= 2 * n; i++) sum2 += a[i];
  if (sum2 - sum1 < 0 || sum2 - sum1 > 1)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (i = 1; i <= 2 * n; i++) cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
}
