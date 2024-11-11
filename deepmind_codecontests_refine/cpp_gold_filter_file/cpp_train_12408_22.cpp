#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r, cnt;
  cin >> l >> r;
  for (long long i = l; i <= r; i++) {
    string s = to_string(i);
    cnt = 0;
    for (long long j = 0; j < s.length(); j++) {
      for (long long k = j + 1; k < s.length(); k++) {
        if (s[j] == s[k]) {
          cnt = 1;
          s.clear();
          break;
        }
      }
    }
    if (cnt == 0) {
      cout << i << endl;
      break;
    }
  }
  if (cnt == 1) {
    cout << -1 << endl;
  }
  return 0;
}
