#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int c = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '8') c++;
  }
  cout << min(n / 11, c);
  return 0;
}
