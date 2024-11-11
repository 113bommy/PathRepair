#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
long long oo = 1e18;
long long const M = 1e9 + 7, N = 1e9 + 9;
long long n, x, c2, mx = -1e9 - 9, ans;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  vector<pair<long long, long long> > v(n);
  vector<long long> c1;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v[i] = make_pair(x, i + 1);
    if (x == 0)
      c1.push_back(i + 1);
    else if (x < 0) {
      c2++;
      if (x >= mx) {
        mx = x;
        ans = i + 1;
      }
    }
  }
  if (c1.size())
    for (int i = 0; i < c1.size() - 1; i++) {
      cout << "1 " << c1[i] << " " << c1[i + 1] << endl;
    }
  if (c2 & 1) {
    if (c1.size()) {
      cout << "1 " << ans << " " << c1[c1.size() - 1] << endl;
      if (c1.size() + c2 < n) cout << "2 " << c1[c1.size() - 1] << endl;
    } else
      cout << "2 " << ans << endl;
  } else if (c1.size() && c1.size() < n)
    cout << "2 " << c1[c1.size() - 1] << endl;
  vector<long long> w;
  for (int i = 0; i < n; i++) {
    if ((ans - 1 == i && c2 % 2 != 0) || v[i].first == 0) continue;
    w.push_back(i + 1);
  }
  if (w.size())
    for (int i = 0; i < w.size() - 1; i++) {
      cout << "1 " << w[i] << " " << w[i + 1] << endl;
    }
  return 0;
}
