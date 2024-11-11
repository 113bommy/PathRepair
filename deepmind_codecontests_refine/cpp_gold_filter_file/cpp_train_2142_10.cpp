#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k, a, b, c;
  cin >> n >> k >> a >> b;
  string s = "";
  char ch = (a > b ? 'G' : 'B'), chh = 'G' + 'B' - ch;
  long long int mi = min(a, b);
  long long int mx = max(a, b), x = mi;
  if (mx > k * (mi + 1)) {
    cout << "NO";
    return;
  }
  long long int p = mx / (mi + 1);
  long long int rem = mx % (mi + 1);
  for (long long int _ = 0; _ < mi + 1; _++) {
    for (long long int __ = 0; __ < p; __++) {
      s += ch;
    }
    if (rem) s += ch, rem--;
    if (x) s += chh, x--;
  }
  cout << s;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
