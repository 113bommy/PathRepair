#include <bits/stdc++.h>
using namespace std;
int n, mx;
string s;
int main() {
  cin >> n >> s;
  vector<int> vc(26), ans(n);
  for (int i = 0; i < n; i++) {
    int c = s[i] - 'a', col = 0;
    for (int j = c + 1; j < 26; j++) {
      col = max(col, vc[j]);
    }
    col++;
    vc[c] = col;
    ans[i] = col;
  }
  cout << *max_element(ans.begin(), ans.end()) << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}
