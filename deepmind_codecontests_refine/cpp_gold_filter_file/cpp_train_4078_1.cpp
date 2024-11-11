#include <bits/stdc++.h>
using namespace std;
const long long INF = 9223372036854775807ll;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, inf = 2147483647,
          M = 998244353;
long long pw(long long a, long long b) {
  long long p = 1;
  while (b)
    if (b % 2) {
      p = (p * a) % M;
      --b;
    } else {
      a = (a * a) % M;
      b /= 2;
    }
  return p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b;
  cin >> a >> b;
  cout << pw(2, a + b) << "\n";
  return 0;
}
