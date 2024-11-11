#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
string s, t;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n;
  cin >> s >> t;
  for (int i = 0; i <= (int)s.size() - 1; i++) {
    if (s[i] == '1' && t[i] == '1')
      c++;
    else if (s[i] == '1')
      a++;
    else if (t[i] == '1')
      b++;
  }
  if (c % 2 == 1) a++;
  if (a > b)
    cout << "First";
  else if (b > a)
    cout << "Second";
  else
    cout << "Draw";
  return 0;
}
