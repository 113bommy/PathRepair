#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int sp = 0;
  for (int i = 0; i < n; i += 3) {
    if (s[i] == '<' && s[i + 1] != '/') sp += 1;
    if (i > 0 && i + 5 < n)
      for (int i = 0; i < sp; i++) {
        cout << " ";
      }
    cout << s[i] << s[i + 1] << s[i + 2];
    if (s[i + 1] == '/') {
      sp -= 1;
      cout << s[i + 3];
      i++;
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  cerr << endl
       << "[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
}
