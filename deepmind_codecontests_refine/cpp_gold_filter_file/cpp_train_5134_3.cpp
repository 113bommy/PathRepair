#include <bits/stdc++.h>
#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
using namespace std;
const int N = 1100;
const int MAXN = int(1e6) + 100;
const int Mmask = (1 << 20);
const long long mod = (long long)(1e9) + 7;
const long long MOD = (long long)(1e18) + 7ll;
int solution();
int main(int argc, char* const argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return solution();
}
long long n;
void check(long long x) {
  long long f = 0, s = 0;
  for (long long i = 2ll; i * i <= x; i++) {
    while (x % i == 0 && (x > i)) {
      if (!f)
        f = i;
      else {
        s = i;
        break;
      }
      x /= i;
    }
    if (s) break;
  }
  if (s || !f) {
    cout << "1\n" << f * s;
    exit(0);
  }
}
int solution() {
  cin >> n;
  check(n);
  cout << 2;
  return 0;
}
