#include <bits/stdc++.h>
using namespace std;
bool vocala(char c) {
  if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
      c == 'o' || c == 'O' || c == 'u' || c == 'U')
    return true;
  return false;
}
int isprime(long long n) {
  if (n == 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return 0;
  return 1;
}
int isfibo(long long n) {
  long long a = 5 * n * n + 4;
  long long b = a - 8;
  if (sqrt(a) == int(sqrt(a)) || sqrt(b) == int(sqrt(b))) return 1;
  return 0;
}
int gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
ifstream in("kfib.in");
ofstream out("kfib.out");
long long const nrmax = 1e18;
int pozitie[5] = {0, 1, 2, 3};
char v[55][55];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  int x1, y1, x2, y2;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> v[i][j];
      if (v[i][j] == 'E') x2 = i, y2 = j;
      if (v[i][j] == 'S') x1 = i, y1 = j;
    }
  }
  string s;
  cin >> s;
  long long ans = 0;
  do {
    int x = x1, y = y1, ok = 0;
    for (char c : s) {
      int u = int(c - '0');
      if (pozitie[u] == 0) --y;
      if (pozitie[u] == 1) ++y;
      if (pozitie[u] == 2) ++x;
      if (pozitie[u] == 3) --x;
      if (v[x][y] == '#' || x > n || x < 1 || y > m || y < 1) break;
      if (x == x2 && y == y2) {
        ok = 1;
        break;
      }
    }
    ans += ok;
  } while (next_permutation(pozitie, pozitie + 4));
  cout << ans << '\n';
  in.close();
  out.close();
  return 0;
}
