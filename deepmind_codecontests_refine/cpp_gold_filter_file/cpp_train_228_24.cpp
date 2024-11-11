#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int N = 2e5 + 1e2;
int t, n, m, l[N];
map<char, int> x;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    x.clear();
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) cin >> l[i];
    sort(l, l + m);
    for (int i = 0; i < l[0]; ++i) x[s[i]] += m;
    for (int i = 0; i < m - 1; i++) {
      for (int k = l[i]; k < l[i + 1]; ++k) {
        x[s[k]] += m - i - 1;
      }
    }
    for (int i = 0; i < n; ++i) x[s[i]]++;
    for (char i = 'a'; i <= 'z'; ++i) cout << x[i] << " ";
    cout << endl;
  }
}
