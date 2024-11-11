#include <bits/stdc++.h>
using namespace std;
long long wwwww[1000010], w1[1000010], l[1000010], r[1000010];
pair<long long, long long> w[6000000];
long long ans, ans1;
long long a, b, c, x, y, z, n, m, q, k, c1, b1, p;
map<pair<long long, long long>, bool> h;
map<long long, long long> M, M1;
vector<long long> v[100003], v1;
long long poww(long long x, long long y) {
  if (x == 0) return 0;
  if (x == 1) return 1;
  if (y == 0) return 1;
  if (y == 1) return x;
  long long d = poww(x, y / 2);
  if (y % 2) return d * d * x;
  return d * d;
}
int main() {
  cin >> w1[0] >> w1[1] >> w1[2];
  sort(w, w + 3);
  if (w1[0] == 1) z = 1;
  if (w1[0] == 2 && w1[1] == 4 && w1[1] == 4) z = 1;
  if (w1[0] == 2 && w1[1] == 2) z = 1;
  if (w1[0] == 3 && w1[1] == 3 && w1[2] == 3) z = 1;
  if (z)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
