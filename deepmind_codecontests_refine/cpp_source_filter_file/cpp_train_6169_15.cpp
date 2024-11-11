#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int max_n = 200005;
void solve() {}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a % 4 != 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
