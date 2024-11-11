#include <bits/stdc++.h>
using namespace std;
const int MAXN = 0;
const int LOGN = 0;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;
long long N, Q;
long long x;
long long f(long long x) {
  if (x & 1) return (x + 1) >> 1;
  long long id = N - (x >> 1);
  id -= id & -id;
  id >>= 1;
  return N - id;
}
void read() {
  cin >> N >> Q;
  while (Q--) {
    cin >> x;
    cout << f(x) << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  read();
  return 0;
}
