#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll OO = 0x3f3f3f3f3f3f3f3fLL;
int di[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int dj[8] = {1, -1, 0, 0, 1, 1, -1, -1};
string ys = "YES", no = "NO";
const int N = 1e5 + 5, M = 5 * (1 << 10) + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = 0;
    for (int i = 0; i < n; i++) {
      int cnta = 0, cntb = 0;
      for (int j = i; j < n; j++) {
        cnta += (s[j] == 'a');
        cntb += (s[j] == 'b');
        if (cnta == cntb) {
          cout << i + 1 << ' ' << j + 1 << '\n';
          ok = 1;
          goto out;
        }
      }
    }
  out:;
    if (!ok) cout << "-1 -1" << '\n';
  }
}
