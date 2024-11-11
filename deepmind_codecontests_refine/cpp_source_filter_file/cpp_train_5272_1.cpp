#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 10;
int const mod = 1e9 + 7;
int n, m;
struct bkn {
  int l, r, u, d, v;
} a[2 * maxn];
void change1(int x) {
  int tx = x;
  do {
    a[a[x].l].v = a[x].v;
    x = a[x].r;
  } while (x != tx);
}
void change2(int x) {
  int tx = x;
  do {
    a[a[x].u].v = a[x].v;
    x = a[x].d;
  } while (x != tx);
}
void check(int x, int y) {
  if (x > y) swap(x, y);
  if (y - x == 1) {
    if (x % m) {
      cout << "x: " << x << ' ' << y << endl;
      cout << "NO" << endl;
      exit(0);
    }
  }
  if (y - x == m) {
    cout << "NO" << endl;
    exit(0);
  }
  return;
}
int main() {
  cin >> n >> m;
  if (n == 3 && m == 3) {
    cout << "YES" << endl;
    cout << "1 8 3" << endl;
    cout << "9 2 4" << endl;
    cout << "5 7 6" << endl;
    return 0;
  }
  if (n == 1 && m == 1) {
    cout << "YES" << endl;
    cout << 1 << endl;
    return 0;
  }
  if (n == 1) {
    if (m <= 3) {
      cout << "NO" << endl;
      return 0;
    }
    cout << "YES" << endl;
    for (int i = 2; i <= m; i += 2) {
      cout << i << ' ';
    }
    for (int i = 1; i <= m; i += 2) {
      cout << i << ' ';
    }
    cout << endl;
    return 0;
  } else if (m == 1) {
    if (n <= 3) {
      cout << "NO" << endl;
      return 0;
    }
    cout << "YES" << endl;
    for (int i = 2; i <= n; i += 2) {
      cout << i << endl;
    }
    for (int i = 1; i <= n; i += 2) {
      cout << i << endl;
    }
    return 0;
  }
  int tot = 0;
  for (int i = 2; i <= n + 1; i++) {
    a[(i - 1) * (m + 1) + 1].l = (i - 1) * (m + 1) + m + 1;
    a[(i - 1) * (m + 1) + 1].r = (i - 1) * (m + 1) + 2;
    for (int j = 2; j <= m + 1; j++) {
      if (i == 2) {
        a[(i - 2) * (m + 1) + j].u = n * (m + 1) + j;
        a[(i - 2) * (m + 1) + j].d = (i - 1) * (m + 1) + j;
      }
      int v = (i - 1) * (m + 1) + j;
      int tv = (i - 2) * m + j - 1;
      int l, r, u, d;
      a[v].v = tv;
      a[v].l = v - 1;
      a[v].r = (j == m + 1 ? v - m : v + 1);
      a[v].u = v - m - 1;
      a[v].d = (i == n + 1 ? j : v + m + 1);
    }
  }
  int ok = 0;
  for (int i = 2; i <= n + 1; i += 2) {
    change1((i - 1) * (m + 1) + 2);
    if (m > 2) {
      change1((i - 1) * (m + 1) + 2);
      ok = 1;
    }
  }
  for (int j = 3; j <= m + 1; j += 2) {
    change2(m + 1 + j);
    if (!ok && n > 2) {
      change2(m + 1 + j);
    }
  }
  for (int j = 2; j <= m + 1; j++) a[j].v = -n * m - 500;
  for (int i = 2; i <= n + 1; i++) a[(i - 1) * (m + 1) + 1].v = -n * m - 500;
  for (int i = 2; i <= n + 1; i++) {
    for (int j = 2; j <= m + 1; j++) {
      int v = (i - 1) * (m + 1) + j;
      int l, r, u, d;
      l = v - 1;
      r = (j == m + 1 ? v - m : v + 1);
      u = v - m - 1;
      d = (i == n + 1 ? j : v + m + 1);
      check(a[l].v, a[v].v);
      check(a[r].v, a[v].v);
      check(a[u].v, a[v].v);
      check(a[d].v, a[v].v);
    }
  }
  cout << "YES" << endl;
  for (int i = 2; i <= n + 1; i++) {
    for (int j = 2; j <= m + 1; j++) {
      int v = (i - 1) * (m + 1) + j;
      cout << a[v].v << ' ';
    }
    cout << endl;
  }
}
