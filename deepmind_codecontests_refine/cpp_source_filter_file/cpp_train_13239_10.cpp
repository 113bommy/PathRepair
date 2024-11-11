#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int count = 0;
  for (int i = s.size() - 1; i > 0; i -= 2) {
    if (s[i] == '1') count = 1;
  }
  if (count == 0)
    count += (s.size() - 1) / 2 + (s.size() - 1) % 2;
  else
    count += (s.size() - 1) / 2;
  cout << count << '\n';
  return 0;
}
