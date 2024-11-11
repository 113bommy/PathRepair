#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long int n, x, y;
  cin >> n >> x >> y;
  max(x - 1, y - 1) <= max(n - x, n - y) ? cout << "White" : cout << "Black";
  return 0;
}
