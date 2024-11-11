#include <bits/stdc++.h>
using namespace std;
int fr[200005];
int ba[200005];
int main() {
  int ans;
  string s, t;
  cin >> s >> t;
  int le1 = s.length();
  int le2 = t.length();
  for (int i = 0, j = 0; i < le1 && j < le2; i++)
    if (s[i] == t[j]) fr[j++] = i;
  for (int i = le1 - 1, j = le2 - 1; i >= 0 && j >= 0; i--)
    if (s[i] == t[j]) ba[j--] = i;
  ans = max(ba[0], le1 - 1 - fr[le2 - 1]);
  for (int i = 1; i < le2; i++) ans = max(ans, ba[i] - fr[i - 1] - 1);
  cout << ans << endl;
  return 0;
}
