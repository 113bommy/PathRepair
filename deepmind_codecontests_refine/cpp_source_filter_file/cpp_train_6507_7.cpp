#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 7;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;
int x;
int mx;
string res;
string s[N];
int main() {
  ios_base::sync_with_stdio(false);
  int n = 0;
  while (getline(cin, s[++n])) {
    mx = max(mx, (int)s[n].size());
  }
  cout << string(mx + 2, '*') << "\n";
  for (int i = 1; i <= n; i++) {
    cout << "*";
    int y = mx - (int)s[i].size();
    if (y % 2) {
      cout << string((y + x) / 2, ' ') << s[i] << string((y + !x) / 2, ' ');
      x ^= 1;
    } else {
      cout << string(y / 2, ' ') << s[i] << string(y / 2, ' ');
    }
    cout << "*\n";
  }
  cout << string(mx + 2, '*') << "\n";
}
