#include <bits/stdc++.h>
using namespace std;
int odd, even, n, k, f[2][500], E, O;
string s;
int main() {
  cin >> s;
  for (k = 0; k <= s.size() - 1; k++) {
    even += f[1 - k % 2]['a' + 'b' - s[k]];
    odd += f[k % 2]['a' + 'b' - s[k]];
    f[k % 2][s[k]]++;
  }
  n = s.size();
  for (k = 1; k <= n; k++) {
    if (k % 2 == 1)
      O += n - k + 1;
    else
      E += n - k + 1;
  }
  cout << E - even << " " << O - odd << endl;
}
