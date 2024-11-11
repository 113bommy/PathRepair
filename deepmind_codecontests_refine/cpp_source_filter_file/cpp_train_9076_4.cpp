#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const long long MOD = 1000000007;
int t;
string str;
bool ans[27];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> t;
  while (t--) {
    int cur = 1;
    memset(ans, 0, sizeof(ans));
    cin >> str;
    for (int i = 1; i <= int(str.size()); i++) {
      if (i == int(str.size()) || str[i] != str[i - 1]) {
        if (cur == 1) {
          ans[str[i - 1] - 'a'] = true;
        }
        cur = 0;
      }
      cur++;
    }
    for (int i = 0; i < 26; i++) {
      if (ans[i]) {
        cout << char(i + 'a');
      }
    }
    cout << '\n';
  }
}
