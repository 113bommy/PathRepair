#include <bits/stdc++.h>
using namespace std;
const int N = 405;
char **a;
char s[N][N];
int n, m, r, c;
bitset<N> R[N];
bitset<N> b[26][N];
bitset<N> shift(bitset<N> b, int x) { return (b << m - x) | (b >> x); }
int main() {
  cin >> n >> m;
  a = new char *[N];
  for (int i = 0; i < N; i++) a[i] = new char[N];
  for (int i = 0; i < N; i++) R[i] = ~R[i];
  for (int i = 0; i < n; i++) {
    scanf("%s", &a[i][0]);
    for (int j = 0; j < m; j++) b[a[i][j] - 'a'][i][j] = 1;
  }
  cin >> r >> c;
  for (int i = 0; i < r; i++) scanf("%s", &s[i][0]);
  for (int x = 0; x < r; x++) {
    for (int y = 0; y < c; y++) {
      if (s[x][y] == '?') continue;
      int k = s[x][y] - 'a';
      for (int i = 0; i < n; i++) R[i] &= shift(b[k][(i + x) % n], y % m);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) putchar(R[i][j] ? '1' : '0');
    puts("");
  }
}
