#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, c = 1;
  string s;
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n - 1; i++) {
    if (s[i] != s[i - 1]) c++;
  }
  if (c + 2 <= n)
    cout << c + 2;
  else
    cout << n;
  return 0;
}
