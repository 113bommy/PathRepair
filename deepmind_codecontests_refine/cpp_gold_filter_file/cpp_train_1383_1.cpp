#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long n = s.length();
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  long long i = 0, j = 1, count = 0, pre_i = 0;
  while (j < n) {
    string k = string(1, s[i]) + s[j];
    if (k == "AB" || k == "BB") {
      i--;
      j++;
      count++;
      if (i < pre_i) {
        j++;
        i = j - 1;
        pre_i = i;
      }
    } else {
      j++;
      i++;
    }
  }
  cout << n - 2 * count << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
