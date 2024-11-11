#include <bits/stdc++.h>
using namespace std;
int parse(long long n, long long m, long long a, long long b) {
  long long ar = a / m;
  long long ac = a % m;
  long long br = b / m;
  long long bc = b % m;
  if (b == n) bc = m - 1;
  if (n == 1) return 1;
  if (m == 1) return 1;
  if (n <= m) return 1;
  if (ar == br) return 1;
  if (ac == 0 && bc == m - 1) return 1;
  if (ac == 0 || bc == m - 1) return 2;
  if (ar == br - 1) return 2;
  if (ac == bc + 1) return 2;
  long long rows = br - ar - 1;
  assert(rows > 0);
  return 3;
}
int main() {
  long long n, m, a, b;
  srand(time(NULL));
  n = rand() % 1000000000 + 1;
  m = rand() % 1000000000 + 1;
  a = rand() % n + 1;
  b = rand() % n + 1;
  if (b < a) {
    long long c = a;
    a = b;
    b = c;
  }
  cin >> n >> m >> a >> b;
  a--;
  b--;
  int ans = 100000;
  ans = parse(n, m, a, b);
  assert(ans <= 3);
  cout << ans << endl;
  return 0;
}
