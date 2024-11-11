#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '<' || s[i] == '>') s[i] = ' ';
  stringstream ss(s);
  int k = 0;
  while (ss >> s) {
    if (s[0] == '/') {
      k--;
      for (int i = 0; i < k; i++) cout << " ";
      cout << "<" << s << ">";
    } else {
      for (int i = 0; i < k; i++) cout << " ";
      cout << "<" << s << ">";
      k++;
    }
    cout << "\n";
  }
  return 0;
}
