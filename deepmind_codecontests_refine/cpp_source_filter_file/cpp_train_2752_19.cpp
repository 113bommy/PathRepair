#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k = 0, a, kol = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a == 1)
      k += a;
    else if (a == -1 && k == 0)
      ++kol;
    else if (k > 0)
      --k;
  }
  cout << kol;
  return 0;
}
