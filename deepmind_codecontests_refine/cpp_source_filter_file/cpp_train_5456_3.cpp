#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
int td, sumd;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n * 2; i++) {
    int x, y;
    char _;
    cin >> x >> _ >> y;
    sumd += y;
    if (y) td++;
  }
  long long mini = inf;
  for (int i = max(n - td, 0); i <= min(td, n); i++)
    mini = min(mini, (long long)abs(sumd - i * 1000));
  int tmp = mini % 1000;
  cout << mini / 1000 << '.';
  if (tmp < 100) cout << 0;
  if (tmp < 10) cout << 0;
  cout << tmp << endl;
  return 0;
}
