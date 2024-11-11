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
int n, m, a[203], b[203];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int i, j, t, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    a[x] = 1;
  }
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> x;
    b[x] = 1;
  }
  for (i = 0; i < 203; i++) {
    if (a[i] == 0) continue;
    for (j = 0; j < 203; j++) {
      if (b[j] == 0) continue;
      x = i + j;
      if (a[x] == 0 && b[x] == 0) {
        cout << i << ' ' << j << endl;
        return 0;
      }
    }
  }
  return 0;
}
