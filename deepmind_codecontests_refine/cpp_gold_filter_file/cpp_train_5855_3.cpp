#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 2; i < n; i++) {
    for (long long int j = n - 1; j > 1; j--) {
      if (i * j == n) {
        if (i <= j) {
          cout << i << j << "\n";
          return;
        }
        cout << j << i << "\n";
        return;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
