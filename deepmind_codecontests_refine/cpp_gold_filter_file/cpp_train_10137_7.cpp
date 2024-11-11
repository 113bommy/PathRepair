#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int c;
  for (c = n; c > 3; c -= 2)
    cout << s[s.size() - c] << s[s.size() - c + 1] << "-";
  for (int c2 = c; c2 > 0; c2--) cout << s[s.size() - c2];
}
