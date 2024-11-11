#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long j = 0, k = 0;
    for (int i = 0; i < s.length(); i++) {
      if ((s[i] - 48) == 1) {
        j = i;
        break;
      }
    }
    for (int i = s.length(); i > j; i--) {
      if ((s[i] - 48) == 1) {
        k = i;
        break;
      }
    }
    int cnt = 0;
    for (int i = j; i < k; i++) {
      if ((s[i] - 48) == 0) {
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}
