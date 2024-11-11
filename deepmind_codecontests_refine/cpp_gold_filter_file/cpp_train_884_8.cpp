#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, a, b, c;
  cin >> n >> a >> b >> c;
  if (a <= b - c || n < b) {
    cout << n / a << endl;
    return;
  }
  long long int d = b - c;
  long long int x = (n - b) % d;
  long long int to = b + x;
  to -= d;
  long long int res = (n - to) / d;
  res += (to / a);
  cout << res << endl;
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  solve();
}
