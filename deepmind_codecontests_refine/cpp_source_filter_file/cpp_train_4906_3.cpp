#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    X = (X << 3) + (X << 1) + ch - '0';
    ch = getchar();
  }
  return w ? -X : X;
}
inline void print(int x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 5e5 + 101;
int n;
struct node {
  int id, cnt;
} a[N];
int f[N], t[N];
bool cmp(node a, node b) { return a.cnt < b.cnt; }
int get(int x) {
  if (x >= 2) return 2;
  return x;
}
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i].cnt = read();
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].cnt == 1) {
      pos = i;
    } else
      break;
  }
  int res = 0;
  for (int i = pos + 1; i <= n; i++) res = res + a[i].cnt - 2;
  if (res + 2 < pos) {
    puts("NO");
    return 0;
  }
  printf("YES ");
  int pos2 = pos;
  cout << n - pos - 1 + get(pos) << endl;
  cout << n - 1 << endl;
  for (int i = pos + 1; i < n; i++) {
    cout << a[i].id << ' ' << a[i + 1].id << endl;
  }
  if (pos > 0) {
    cout << a[1].id << ' ' << a[pos + 1].id << endl;
    --pos;
    if (pos > 0) cout << a[2].id << ' ' << a[n].id << endl;
  }
  for (int i = pos + 1; i <= n; i++)
    if (a[i].cnt >= 2) a[i].cnt -= 2;
  int pos3 = 3;
  if (pos > 0) {
    for (int i = pos2 + 1; i <= n; i++) {
      if (pos == 0) break;
      for (int j = 1; j <= a[i].cnt; j++) {
        if (pos == 0) break;
        cout << a[pos3].id << ' ' << a[i].id << endl;
        --pos;
        ++pos3;
      }
    }
  }
}
