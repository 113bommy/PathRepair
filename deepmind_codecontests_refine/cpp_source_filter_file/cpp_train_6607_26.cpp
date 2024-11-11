#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i;
  cin >> n;
  cout << n << " ";
  for (i = 1; i <= n - 1; i++) cout << n + 1 - i << " ";
  cout << "\n";
  return 0;
}
