#include <bits/stdc++.h>
const long long inf = (long long)(1e18 + 7);
using namespace std;
int n, k;
int main() {
  cin >> n >> k;
  int a = (n - k) / 2;
  for (int i = 0; i < n; ++i) cout << (((i + 1) % (a + 1)) == 0);
  cout << endl;
  return 0;
}
