#include <bits/stdc++.h>
using namespace std;
long long n, m, k, l, x, x2, y, y2, nowel;
int gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long maxo = 0;
  cin >> n;
  vector<vector<int>> b(n + 1, vector<int>(1000, 0));
  for (int i = 1; i <= n; i++) cin >> b[i][1];
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= n * 2; j++) b[i][j] = b[b[i][j - 1]][1];
  }
  vector<long long> c;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (b[i][j] == b[i][j * 2]) {
        if (b[i][j] == i)
          c.push_back(j);
        else
          ans = max(ans, j);
        break;
      }
    }
  maxo = 1;
  for (int i = 0; i < c.size(); i++) maxo = (maxo) / gcd(maxo, c[i]) * c[i];
  long long anse = 0;
  while (anse < ans) {
    anse += maxo;
  }
  cout << anse;
}
