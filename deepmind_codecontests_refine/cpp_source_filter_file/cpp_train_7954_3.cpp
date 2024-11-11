#include <bits/stdc++.h>
using namespace std;
string s;
int k, l;
int main() {
  cin >> s;
  k = s.find('^');
  for (int i = 0; i < k; i++)
    if (s[i] - 48 < 10) l += (s[i] - 48) * (k - i);
  for (int i = k + 1; i < s.size(); i++)
    if (s[i] - 48 < 10) l -= (s[i] - 48) * (i - k);
  cout << (l > 0 ? "left" : l == 0 ? "balance" : "right");
}
