#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long long res = 0;
  for (int i = 2; i <= n / 2; i++) {
    int x = n / i;
    res += 4 * ((x * (x + 1)) / 2 - 1);
  }
  cout << res;
}
