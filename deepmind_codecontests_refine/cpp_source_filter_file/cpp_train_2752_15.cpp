#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, x;
  cin >> n;
  int total, ans = 0;
  while (n--) {
    cin >> x;
    if (x == -1) {
      if (!total)
        ans++;
      else
        total--;
    } else
      total += x;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  { solve(); }
  return 0;
}
