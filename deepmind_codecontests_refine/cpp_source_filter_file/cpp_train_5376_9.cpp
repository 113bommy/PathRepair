#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1000 + 10;
const int M = 100000 + 10;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double EXP = 1E-8;
const int INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long p = 1;
  while (n--) {
    p *= 2;
    if (p >= m) break;
  }
  cout << m % p << endl;
  return 0;
}
