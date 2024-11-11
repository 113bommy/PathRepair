#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int func(int a, int b, int n) {
  if (n == 0) return a;
  if (n == 1) return b;
  if (n % 3 == 2) return a ^ b;
  if (n % 3 == 0) return 0 ^ a;
  if (n % 3 == 1) return 0 ^ b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, a, b, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b >> n;
    cout << func(a, b, n) << '\n';
  }
}
