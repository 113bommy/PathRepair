#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    cin >> n >> s;
    long long min1 = n, max1 = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (i > max1) max1 = i;
        if (i < min1) min1 = i;
      }
    }
    if (max1 == -1)
      cout << n << endl;
    else
      cout << max(max1 - 0, abs(n - min1)) * 2 << endl;
  }
  return 0;
}
