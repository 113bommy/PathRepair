#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long long int x = s.size();
  vector<char> c;
  c.push_back(s[x - 1]);
  char ch = s[x - 1];
  for (long long int i = x - 2; i >= 0; i--) {
    if (ch <= s[i]) {
      c.push_back(s[i]);
      ch = s[i];
    }
  }
  long long int y = c.size();
  for (long long int i = y - 1; i >= 0; i--) {
    cout << c[i];
  }
}
