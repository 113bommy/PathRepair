#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, loc = 1;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] > s[i + 1]) {
      loc = i;
      break;
    }
  }
  s.erase(s.begin() + loc);
  cout << s;
}
