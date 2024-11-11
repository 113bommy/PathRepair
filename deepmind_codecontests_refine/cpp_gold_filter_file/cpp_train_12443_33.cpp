#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const long long INF = (long long)2e9 + 1;
const long long LINF = (long long)8e18;
const long long MM = (long long)1e9 + 7;
int solve();
void gen();
int main() {
  solve();
  return 0;
}
const int MAXN = 1e5 + 7;
const int MAXC = 5e7;
int solve() {
  long long a, b;
  cin >> a >> b;
  if ((a - b) % 2 || a < b) {
    cout << 0;
    return 0;
  }
  long long cur = abs(a - b) / 2;
  long long cnt = 0;
  for (long long i = 0; i < 60; i++) {
    if ((1LL << i) & b) {
      cnt++;
    }
  }
  for (long long i = 60; i >= 0; i--) {
    if (!(b & (1LL << i)) && cur & (1LL << i)) cur -= (1LL << i);
  }
  cur ? cout << 0 : cout << (a - b != 0 ? (1LL << cnt) : (1LL << cnt) - 2);
  return 0;
}
