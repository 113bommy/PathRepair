#include <bits/stdc++.h>
using namespace std;
long long t, n;
string s;
long long cnt;
void solve() {
  cnt = 0;
  cin >> n;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] = '(')
      cnt++;
    else {
      if (cnt > 0) cnt--;
    }
  }
  cout << cnt << endl;
}
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
