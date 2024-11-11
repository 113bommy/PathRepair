#include <bits/stdc++.h>
using namespace std;
string B = "BRG";
string R = "RGB";
string G = "GBR";
string s;
int l, r, k, n, res, t;
int inB, inR, inG;
void solve() {
  res = 1000000;
  cin >> n >> k;
  cin >> s;
  l = r = inB = inR = inG = 0;
  while (r < n) {
    if (r - l == k) {
      res = min(res, min(inB, min(inR, inG)));
      if (s[l] != B[l % 3]) inB--;
      if (s[l] != G[l % 3]) inG--;
      if (s[l] != R[l % 3]) inR--;
      l++;
    }
    if (s[r] != B[r % 3]) inB++;
    if (s[r] != G[r % 3]) inG++;
    if (s[r] != R[r % 3]) inR++;
    r++;
  }
  res = min(res, min(inB, min(inG, inR)));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    solve();
    cout << res << '\n';
  }
  return 0;
}
