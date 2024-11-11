#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int odd = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x & 1) odd++;
  }
  cout << (odd & 1 ? 1 : n - odd);
  return 0;
}
