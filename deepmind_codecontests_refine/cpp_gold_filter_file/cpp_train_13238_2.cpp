#include <bits/stdc++.h>
using namespace std;
ifstream fin("Codeforces.in");
ofstream fout("Codeforces.out");
int n, m, t[200005], c[101], tt[200005];
string ans;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> t[i];
  tt[0] = t[0];
  for (int i = 0; i < n; i++) tt[i] = tt[i - 1] + t[i];
  for (int i = 0; i < n; i++) {
    int at = tt[i], used = 0, totalused = 0;
    if (tt[i] <= m) {
      ans += "0 ";
      c[t[i]]++;
      continue;
    }
    for (int k = 100; k >= 1; k--) {
      used = min(c[k], (int)ceil(((at - m) / (double)k)));
      at -= used * k;
      totalused += used;
      if (at <= m) break;
    }
    ans += to_string(totalused) + " ";
    c[t[i]]++;
  }
  cout << ans << "\n";
  return 0;
}
