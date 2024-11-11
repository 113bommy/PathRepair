#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
int a, b, p;
string second;
void solve() {
  cin >> a >> b >> p >> second;
  int n = (int)(second).size();
  ll t = 0;
  for (int i = 0; i < n;) {
    int c = 0;
    t += second[i] == 'A' ? a : b;
    while (i < n && second[i] == second[i - c]) {
      ++c;
      ++i;
    }
  }
  if (second[n - 1] != second[n - 2]) t -= second[n - 1] == 'A' ? a : b;
  int i = 0;
  while (t > p && i < n) {
    t -= second[i] == 'A' ? a : b;
    int c = 0;
    while (i < n && second[i] == second[i - c]) {
      ++c;
      ++i;
    }
  }
  cout << min(n, i + 1) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
