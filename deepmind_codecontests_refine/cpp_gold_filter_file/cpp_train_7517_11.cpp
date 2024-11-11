#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
string t[10];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0, 0},
    dy[] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};
bool dfs(int x, int y, int ti) {
  if (x == 0 && y == 7) return 1;
  int xx, yy;
  for (int(i) = 0; (i) < (9); (i)++) {
    xx = x + dx[i];
    yy = y + dy[i];
    if (xx < 0 || yy < 0 || xx > 7 || yy > 7) continue;
    if (xx - ti >= 0 && t[xx - ti][yy] == 'S') continue;
    if (xx - ti - 1 >= 0 && t[xx - ti - 1][yy] == 'S') continue;
    if (dfs(xx, yy, ti + 1)) return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  for (int(i) = 0; (i) < (8); (i)++) {
    cin >> t[i];
  }
  if (dfs(7, 0, 0))
    cout << "WIN";
  else
    cout << "LOSE";
  return 0;
}
