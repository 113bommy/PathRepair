#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long power(unsigned long long a, unsigned long long b,
                unsigned long long ret = 1LL) {
  while (b--) ret = (ret * a);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c;
  cin >> r >> c;
  if (r * c == 1) return cout << 0, 0;
  if (c == 1) {
    for (int i = 1; i <= (int)(r); ++i) cout << i + 1 << "\n";
    return 0;
  }
  for (int i = 1; i <= r; i++) {
    for (int j = r + 1; j <= r + c; j++) cout << i * j << " ";
    cout << endl;
  }
  return 0;
}
