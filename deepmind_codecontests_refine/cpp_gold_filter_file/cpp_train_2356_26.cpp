#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int a[3333];
void solve(istream& cin, ostream& cout) {
  int n;
  cin >> n;
  for (int i = (0); i < int(n); ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = (1); i < int(n - 1); ++i) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      ans++;
    }
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
      ans++;
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve(cin, cout);
  return 0;
}
