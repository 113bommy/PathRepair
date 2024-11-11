#include <bits/stdc++.h>
using namespace std;
bool accept(string x) {
  long long count = 0, i = 0, m = x.size();
  while (i < m) {
    if (x[i] == '1' || x[i] == '0') {
      if (x[i] == '1') count++;
    } else
      return false;
    if (count > 1) return false;
    i++;
  }
  if (count > 1)
    return false;
  else
    return true;
}
int main() {
  long long n;
  cin >> n;
  bool mera = false;
  bool zero = false;
  long long count = 0, pos;
  string s, ank;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    if (accept(s)) {
      if (s != "0") {
        long long len = s.size();
        count = count + len - 1;
      } else
        zero = true;
    } else {
      ank = s;
      mera = true;
    }
  }
  if (!mera && !zero) {
    cout << 1;
    while (count--) cout << 0;
    return 0;
  }
  if (zero) {
    cout << 0;
    return 0;
  } else {
    cout << ank;
    if (count >= 1)
      while (count--) cout << 0;
  }
  return 0;
}
