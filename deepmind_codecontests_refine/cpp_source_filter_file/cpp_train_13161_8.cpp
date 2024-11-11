#include <bits/stdc++.h>
using namespace std;
int n;
string s, c;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> s >> c;
  n = s.size();
  int r = 0;
  while (s[r] == c[r]) r++;
  int l = c.size() - 1;
  while (l >= 0 && s[l] == c[l]) l--;
  if (r > l)
    cout << r - l << "\n";
  else {
    cout << 0;
    return 0;
  }
  for (int i = l + 1; i <= r; i++) cout << i + 1 << " ";
  return 0;
}
