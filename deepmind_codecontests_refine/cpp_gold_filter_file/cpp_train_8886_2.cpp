#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, c = 0;
  string s;
  cin >> n >> s;
  for (i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) c++;
  }
  cout << c << endl;
}
