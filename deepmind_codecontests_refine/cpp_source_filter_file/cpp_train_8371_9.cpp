#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long count = 1, ans = 0;
  for (long long i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      count++;
    } else {
      if (count % 2 == 0) ans++;
      count = 1;
    }
  }
  cout << ans;
}
