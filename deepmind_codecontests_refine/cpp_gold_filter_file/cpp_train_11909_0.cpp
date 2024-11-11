#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const int MOD = 1073741824;
bool isPowerOfTwo(long long int x) { return x && (!(x & (x - 1))); }
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};
int main() {
  fastio();
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2 == 0)
      cout << -1;
    else {
      for (int J = 0; J < (2); J++) {
        for (int i = 0; i < (n); i++) cout << i << " ";
        cout << "\n";
      }
      for (int i = 0; i < (n); i++) {
        cout << (i + i) % n << " ";
      }
    }
  }
  return 0;
}
