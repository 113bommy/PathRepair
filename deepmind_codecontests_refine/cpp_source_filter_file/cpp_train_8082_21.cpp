#include <bits/stdc++.h>
using namespace std;
int k, n;
void solve() { cout << min(k, n - k) + (k - min(n, k)) / 3; }
int main() {
  int a;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a & 1) k++;
  }
  solve();
}
