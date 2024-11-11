#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else if (a > b)
    gcd(b, a % b);
  else
    gcd(a, b % a);
}
string solver(string p) {
  sort(p.begin(), p.end());
  string res;
  int si = 0;
  for (int i = 0; i < p.size(); i++) {
    if (si == 0) {
      res += p[i];
      si++;
    } else if (p[i] != res[si - 1]) {
      res += p[i];
      si++;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int row, col;
  if (k + 1 <= n) {
    row = k + 1;
    col = 1;
  } else {
    k -= n;
    if (k == 0) {
      col = 2;
    } else if ((k / (m - 1)) % 2 == 0) {
      col = 1 + k % (m - 1);
    } else {
      col = m - k % (m - 1);
    }
    row = n - (k / (m - 1));
  }
  cout << row << " " << col;
  return 0;
}
