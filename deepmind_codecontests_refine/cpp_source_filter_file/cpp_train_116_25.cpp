#include <bits/stdc++.h>
using namespace std;
string s;
string t;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  cin >> s;
  for (int i = 1; i < s.size(); i++)
    if (s[i] < s[i - 1]) {
      cout << "YES\n";
      cout << i - 1 << ' ' << i;
      return 0;
    }
  cout << "NO";
}
