#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, res;
  cin >> n;
  res = 2 * (n / 3);
  if (n % 3) {
    res++;
  }
  cout << res << "\n";
  return 0;
}
