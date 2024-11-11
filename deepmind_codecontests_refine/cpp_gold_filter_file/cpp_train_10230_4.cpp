#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        int res = 0;
        int i1 = i, j1 = j;
        for (char c : s) {
          if ((c - '0') == i1) {
            ++res;
            swap(i1, j1);
          }
        }
        if ((res % 2) == 1 && i1 != j1) {
          --res;
        }
        ans = max(ans, res);
      }
    }
    cout << (s.length()) - ans << '\n';
  }
}
