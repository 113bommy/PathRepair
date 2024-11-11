#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  if (s.length() < 26) {
    cout << -1;
    return 0;
  } else {
    long long j = 97;
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] == j) {
        j++;
      } else if (s[i] == j - 1) {
        s[i] = j;
        j++;
      }
      if (j == 123) {
        cout << s;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
