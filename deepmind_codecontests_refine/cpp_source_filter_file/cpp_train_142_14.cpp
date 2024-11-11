#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long len = s.length();
  for (int i = 0; i < len - 1; i += 2) {
    for (int j = 0; j < len; j++) {
      if (s[j] > s[j + 2]) swap(s[j], s[j + 2]);
    }
  }
  cout << s;
}
