#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  int ind = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[ind - 1] == t[i]) ind++;
  }
  cout << ind;
}
