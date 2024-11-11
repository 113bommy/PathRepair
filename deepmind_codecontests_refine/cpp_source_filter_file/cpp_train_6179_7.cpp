#include <bits/stdc++.h>
using namespace std;
long n, m;
long a, b;
long ar[1050][1050];
long ans;
bool check(long a, long b) {
  if (a <= 0 || b <= 0 || a + 2 > n || b + 2 > m) return false;
  if (ar[a][b] == 0) return false;
  if (ar[a + 1][b] == 0) return false;
  if (ar[a][b + 1] == 0) return false;
  if (ar[a + 2][b] == 0) return false;
  if (ar[a][b + 2] == 0) return false;
  if (ar[a + 2][b + 1] == 0) return false;
  if (ar[a + 1][b + 2] == 0) return false;
  if (ar[a + 2][b + 2] == 0) return false;
  if (ar[a + 1][b + 1] == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  ans = 1e9;
  for (long iter = 1; iter <= m; iter++) {
    cin >> a >> b;
    ar[a][b] = 1;
    for (int i = a - 2; i <= a + 2; i++)
      for (int j = b - 2; j <= b + 2; j++)
        if (check(i, j)) ans = min(ans, iter);
  }
  if (ans > m * 2) ans = -1;
  cout << ans << endl;
  cin.get();
  cin.get();
  return 0;
}
