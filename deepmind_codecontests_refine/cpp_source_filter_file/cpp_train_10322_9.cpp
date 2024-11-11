#include <bits/stdc++.h>
using namespace std;
const long long mxN = 1e5 + 5;
const long long base = 311;
const long long oo = 1e15;
const long long MOD = 1e9 + 7;
const long double EPS = 1e-10;
const long long bignumbase = 1000000000;
const long long bignumdigits = 9;
const long long d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const long long d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
                d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
long long TestCase;
long long n;
long long a[mxN], trai[mxN], phai[mxN];
void Solve() {
  cin >> n;
  for (long long i = (long long)1; i <= (long long)n; i++) cin >> a[i];
  for (long long i = (long long)n; i >= (long long)1; i--)
    trai[i] = trai[i + 1] + (a[i] == 0), phai[i] = phai[i + 1] + (a[i] == 1);
  for (long long i = (long long)1; i <= (long long)n; i++) {
    if (phai[i + 1] == 0 || trai[i + 1] == 0) {
      cout << i;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  TestCase = 1;
  while (TestCase--) Solve();
  return 0;
}
