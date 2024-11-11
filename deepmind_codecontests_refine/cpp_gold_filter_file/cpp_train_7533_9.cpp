#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c;
char ans[111][111];
inline bool ok(int i, int j) { return (i >= 0 && j >= 0 && i < n && j < m); }
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
inline void putc(int i, int j) {
  for (int let = 'a'; let <= 'z'; ++let) {
    bool can = 1;
    for (int(first) = 0; (first) < (2); ++(first))
      for (int(second) = 0; (second) < (2); ++(second))
        for (int(k) = 0; (k) < (4); ++(k))
          if (ok(i + first + dx[k], j + second + dy[k]) &&
              ans[i + first + dx[k]][j + second + dy[k]] == let)
            can = 0;
    if (can) {
      for (int(first) = 0; (first) < (2); ++(first))
        for (int(second) = 0; (second) < (2); ++(second))
          ans[i + first][j + second] = let;
      --c;
      return;
    }
  }
}
inline void puta(int i, int j) {
  for (int let = 'a'; let <= 'z'; ++let) {
    bool can = 1;
    for (int(second) = 0; (second) < (2); ++(second))
      for (int(k) = 0; (k) < (4); ++(k))
        if (ok(i + dx[k], j + second + dy[k]) &&
            ans[i + dx[k]][j + second + dy[k]] == let)
          can = 0;
    if (can) {
      for (int(second) = 0; (second) < (2); ++(second))
        ans[i][j + second] = let;
      --a;
      return;
    }
  }
}
inline void putb(int i, int j) {
  for (int let = 'a'; let <= 'z'; ++let) {
    bool can = 1;
    for (int(first) = 0; (first) < (2); ++(first))
      for (int(k) = 0; (k) < (4); ++(k))
        if (ok(i + first + dx[k], j + dy[k]) &&
            ans[i + first + dx[k]][j + dy[k]] == let)
          can = 0;
    if (can) {
      for (int(first) = 0; (first) < (2); ++(first))
        for (int(second) = 0; (second) < (2); ++(second))
          ans[i + first][j] = let;
      --b;
      return;
    }
  }
}
int main() {
  cin >> n >> m >> a >> b >> c;
  if ((n & 1 && m & 1) || (n & 1 && m / 2 > a) || (m & 1 && n / 2 > b)) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  a = (n & 1) * (m / 2) + (((a - (n & 1) * (m / 2)) >> 1) << 1);
  b = (m & 1) * (n / 2) + (((b - (m & 1) * (n / 2)) >> 1) << 1);
  if (2 * a + 2 * b + 4 * c < n * m) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  for (int(i) = 0; (i) < (n); ++(i))
    for (int(j) = 0; (j) < (m); ++(j)) ans[i][j] = '0';
  if (n & 1) {
    for (int(j) = 0; (j) < (m); ++(j)) {
      puta(0, j);
      j++;
    }
  }
  if (m & 1) {
    for (int(i) = 0; (i) < (n); ++(i)) {
      putb(i, 0);
      i++;
    }
  }
  for (int(i) = 0; (i) < (n); ++(i))
    for (int(j) = 0; (j) < (m); ++(j))
      if (ans[i][j] == '0') {
        if (c)
          putc(i, j);
        else if (b)
          putb(i, j);
        else
          puta(i, j);
      }
  for (int(i) = 0; (i) < (n); ++(i)) {
    for (int(j) = 0; (j) < (m); ++(j)) cout << ans[i][j];
    cout << endl;
  }
}
