#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  cin >> s;
  int d = 0;
  int c = 0;
  for (int i = 0; i <= n; ++i)
    if (s[i] == '#')
      c++;
    else {
      d = max(d, c);
      c = 0;
    }
  if (d < k)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
