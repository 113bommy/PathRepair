#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
int main() {
  int n, ans = 1;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    ans *= 3;
    ans = ans % N;
  }
  cout << ans << '\n';
}
