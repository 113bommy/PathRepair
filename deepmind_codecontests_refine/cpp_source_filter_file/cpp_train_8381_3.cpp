#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int c = 0;
  for (int i = 0; i < s.size(); ++i)
    if (s[i] == '0' || s[i] == '4' || s[i] == '8') c++;
  for (int i = 0; i < s.size() - 1; ++i) {
    int sum = (s[i] - '0') * 10 + (s[i + 1] - '0');
    if (sum % 4 == 0) c += i + 1;
  }
  cout << c;
}
