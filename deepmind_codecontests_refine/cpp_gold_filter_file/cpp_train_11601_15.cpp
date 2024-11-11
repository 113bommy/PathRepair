#include <bits/stdc++.h>
using namespace std;
const int TAM = 30000 + 15;
const long long MOD = 1000000007LL;
const double PI = 3.14159265359;
long long add(long long x, long long y) { return (x + y + 2 * MOD) % MOD; }
long long mult(long long x, long long y) {
  return (add(x, 0) * add(y, 0)) % MOD;
}
long long fast_expo(long long x, long long y) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  long long res = 1;
  long long mid = fast_expo(x, y / 2);
  if (y % 2 != 0) res = x;
  return mult(mult(mid, mid), res);
}
long long inver(long long x) { return fast_expo(x, MOD - 2); }
long long gcd(long long e1, long long e2) {
  if (e2 == 0) return e1;
  return gcd(e2, e1 % e2);
}
vector<vector<int> > v;
void llegar(int x, int y) {
  for (int i = 1; i <= x; i++) {
    printf("(%d, 1) ", i);
  }
  for (int j = 2; j <= y; j++) {
    printf("(%d, %d) ", x, j);
  }
  puts("");
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int cost = 0;
  vector<int> d(3);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      d[0] = i + j - 1;
      d[1] = i;
      d[2] = j;
      v.push_back(d);
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < k; i++) cost += v[i][0];
  cout << cost << endl;
  for (int i = k - 1; i >= 0; i--) {
    llegar(v[i][1], v[i][2]);
  }
  return 0;
}
