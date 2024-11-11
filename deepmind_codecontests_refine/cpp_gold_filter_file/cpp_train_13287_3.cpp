#include <bits/stdc++.h>
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
using namespace std;
void solve() {
  long long int n, a, b;
  cin >> n >> a >> b;
  for (long long int i = min(a, b); i > 0; i--) {
    if (((a / i) + (b / i)) >= n) {
      cout << i << endl;
      return;
    }
  }
}
int main() {
  solve();
  return 0;
}
