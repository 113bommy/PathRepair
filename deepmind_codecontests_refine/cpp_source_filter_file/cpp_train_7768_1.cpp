#include <bits/stdc++.h>
using namespace std;
using lint = long long;
void solve(istream& cin, ostream& cout) {
  int n, x;
  cin >> n >> x;
  int s = 0;
  for (int i = (0); i < int(n); ++i) {
    int a;
    cin >> a;
    s += a;
  }
  if (s + x - 1 == n) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve(cin, cout);
  return 0;
}
