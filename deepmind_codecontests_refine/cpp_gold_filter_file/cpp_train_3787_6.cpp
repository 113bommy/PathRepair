#include <bits/stdc++.h>
using namespace std;
long long n, i, j, t;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> t;
  cin >> s;
  for (i = 1; i <= t; i++) {
    for (j = 0; j < s.size() - 1; j++) {
      if (s[j] == 'B' && s[j + 1] == 'G') {
        s[j] = 'G';
        s[j + 1] = 'B';
        j++;
      }
    }
  }
  cout << s << '\n';
  return 0;
}
