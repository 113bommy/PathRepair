#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long int inf64 = 1e18;
const int mod = inf + 7;
const int N = 2e5 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long r;
  cin >> r;
  int maxm = 1e6 + 1;
  bool ok = false;
  for (int x = 1; x < maxm; x++) {
    if ((r - x * x - x - 1 > 0) && (r - x * x - x - 1) % (2 * x) == 0) {
      cout << x << " " << (r - x * x - x - 1) / (2 * x) << endl;
      ok = true;
      break;
    }
  }
  if (!ok) cout << "NO\n";
}
