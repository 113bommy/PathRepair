#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
void init_ios() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
int n;
int main() {
  init_ios();
  cin >> n;
  cout << n << "\n";
  for (int i = 1; i <= n; ++i) cout << "1 ";
  cout << "\n";
}
