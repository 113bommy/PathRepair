#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int o = 0, i = 0;
  for (char c : s)
    if (c == 'o')
      o++;
    else
      i++;
  if (o == 0)
    cout << "YES";
  else
    cout << (i % o == 0 ? "YES" : "NO");
}
