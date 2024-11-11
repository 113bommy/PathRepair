#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, r = 0, d = 0;
    cin >> n >> m;
    string s, t;
    for (int i = 0; i < n; i++) {
      cin >> s;
      if (i == n - 1) {
        for (int j = 0; j < s.size() - 1; j++) {
          if (s[j] == 'D') d++;
        }
      }
      if (s[s.size() - 1] == 'R') r++;
    }
    cout << r + d << endl;
  }
}
