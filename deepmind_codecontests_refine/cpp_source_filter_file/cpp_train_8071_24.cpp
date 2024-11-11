#include <bits/stdc++.h>
using namespace std;
int i, k, j, mod = 1e9 + 7, val[500];
long long ans = 1;
string s;
int main() {
  k = 0;
  for (i = 0; i <= 9; i++) val[i] = k++;
  for (i = 'A'; i <= 'Z'; i++) val[i] = k++;
  for (i = 'a'; i <= 'z'; i++) val[i] = k++;
  val['-'] = 62;
  val['_'] = 63;
  cin >> s;
  for (i = 0; i < s.length(); i++)
    for (j = 0; j < 6; j++)
      if (!(val[s[i]] & (1 << j))) ans = (ans * 3) % mod;
  cout << ans;
}
