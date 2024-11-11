#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int bal = 0;
  for (int i = 0; i < n - 10; i++) {
    if (s[i] == '8')
      bal++;
    else
      bal--;
  }
  if (bal)
    cout << "YES";
  else
    cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
