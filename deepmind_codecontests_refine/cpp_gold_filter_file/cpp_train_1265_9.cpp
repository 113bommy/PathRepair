#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int len = (n - k) / 2 + 1;
  for (int i = 1; i <= n; i++) {
    if (i % len == 0)
      cout << "1";
    else
      cout << "0";
  }
  cout << "\n";
  return 0;
}
