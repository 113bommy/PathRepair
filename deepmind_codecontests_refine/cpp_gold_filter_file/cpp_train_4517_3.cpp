#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) cout << n - i << " ";
  cout << 1 << " ";
  for (int i = 2; i <= n - k; i++) cout << i << " ";
  return 0;
}
