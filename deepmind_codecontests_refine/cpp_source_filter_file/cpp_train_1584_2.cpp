#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
long long ans = 0;
long long n, m, k, q;
bool Com(long long v) {
  if (v <= 3) return false;
  if (v % 2 == 0) return true;
  for (long long i = 3; i * i <= v; i += 2) {
    if (v % i == 0) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long a = 1;
  while (true) {
    if (Com(a) && Com(a + n)) {
      cout << a << " " << a + n << "\n";
      return 0;
    }
    ++a;
  }
  return 0;
}
