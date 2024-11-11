#include <bits/stdc++.h>
using namespace std;
const long long int INF = (1LL << 60) - 1;
const long long int MAX = 100000000001;
const long long int MOD = 1000000007;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int k, a, b, v;
  cin >> k >> a >> b >> v;
  int i = 0;
  for (i = 1; i < 10000; i++) {
    int space = 1;
    if (b >= (k - 1)) {
      b -= (k - 1);
      space = k;
    } else {
      space = b + 1;
      b = 0;
    }
    if (a > space * v) {
      a -= space * v;
    } else
      break;
  }
  cout << i << '\n';
  return 0;
}
