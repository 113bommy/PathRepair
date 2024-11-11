#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, k, l, m, n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  while (t--) {
    for (i = 0; i < n; i++) {
      if ((i + 1 < n) && (s[i] == 'B') && (s[i + 1] == 'G')) {
        swap(s[i], s[i + 1]);
        i += 2;
      }
    }
  }
  cout << s;
  return 0;
}
