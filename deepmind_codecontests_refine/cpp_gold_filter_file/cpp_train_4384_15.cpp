#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 10;
long long a1, a2, a3, a4, a5, a6, a7, a8, a9, ans, n, m;
int inp[mm];
string s, s1;
void input() { cin >> a1 >> a2 >> a3; }
void solve() {
  for (int i = 0; a4 < a3; i += 4) {
    ans += (a1 - i) * (a2 - i) - (a1 - i - 2) * (a2 - i - 2);
    a4++;
  }
  cout << ans << endl;
}
int main() {
  input();
  solve();
  return 0;
}
