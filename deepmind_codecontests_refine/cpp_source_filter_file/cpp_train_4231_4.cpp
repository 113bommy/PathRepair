#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)(2e5 + 1);
int freq[maxn];
int main() {
  srand(chrono::steady_clock::now().time_since_epoch().count());
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a;
  cin >> n;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    cin >> a;
    freq[a]++;
  }
  int ans = 0;
  for (__typeof((int)(2e5 + 1)) i = (0) - ((0) > ((int)(2e5 + 1)));
       i != ((int)(2e5 + 1)) - ((0) > ((int)(2e5 + 1)));
       i += 1 - 2 * ((0) > ((int)(2e5 + 1)))) {
    ans += max(0, freq[i] - 1);
  }
  cout << ans;
  return 0;
}
