#include <bits/stdc++.h>
using namespace std;
int n, k;
string s[9];
int e[9], a[9];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < k; i++) {
    a[i] = i;
  }
  int ans = 1e9;
  do {
    int minn = 1e9;
    int maxx = -1;
    for (int i = 0; i < n; i++) {
      string d = "";
      for (int j = 0; j < s[i].length(); j++) {
        d = d + s[i][a[j]];
      }
      e[i] = stoi(d);
    }
    for (int i = 0; i < n; i++) {
      minn = min(minn, e[i]);
      maxx = max(maxx, e[i]);
    }
    ans = min(ans, maxx - minn);
  } while (next_permutation(a, a + k));
  cout << ans << endl;
}
