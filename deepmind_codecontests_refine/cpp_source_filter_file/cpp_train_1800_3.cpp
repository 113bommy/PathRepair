#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
int cont(string s) {
  int um = 0;
  int zero = 0;
  for (int i = 1; i < s.size(); i++)
    if (s[i] == '1' and s[i] == s[i - 1]) um++;
  for (int i = 1; i < s.size(); i++)
    if (s[i] == '1' and s[i] == s[i - 1]) zero++;
  return max(um, zero);
}
int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << cont(s) << '\n';
  }
  return 0;
}
