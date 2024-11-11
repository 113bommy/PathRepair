#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    char bl = s[i];
    int bd = 0;
    for (char p = 'a'; p <= 'z'; p++) {
      int d = abs(p - s[i]);
      if (d <= k && (d > bd)) {
        bd = d;
        bl = p;
      }
    }
    k -= bd;
    s[i] = bl;
  }
  if (k > 0)
    cout << "-1";
  else
    cout << s;
}
