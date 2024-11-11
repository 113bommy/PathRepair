#include <bits/stdc++.h>
using namespace std;
const int ans[] = {0,  4,         10,        20,        35,       56,
                   83, 350 - 234, 400 - 245, 450 - 252, 500 - 256};
int main() {
  int n;
  cin >> n;
  if (n <= 10)
    cout << ans[n] << endl;
  else
    cout << 1LL * n * 50 - n - 247 << endl;
  return 0;
}
