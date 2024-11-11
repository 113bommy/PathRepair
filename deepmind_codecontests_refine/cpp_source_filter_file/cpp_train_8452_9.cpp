#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll mod = 1e9 + 7;
const int N = 3e5 + 5;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, x, a, b;
    scanf("%d%d%d%d", &n, &x, &a, &b);
    cout << min(n, abs(a - b + x)) << endl;
  }
  return 0;
}
