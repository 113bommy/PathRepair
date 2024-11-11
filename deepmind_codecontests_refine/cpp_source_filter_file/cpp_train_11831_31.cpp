#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t = "aeiou13579";
  cin >> s;
  int k = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s.find(s[i]) < 10) k++;
  }
  cout << k;
}
