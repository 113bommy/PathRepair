#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m >> k;
    cout << (m - 1) * 9 + k << "\n";
  }
}
