#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string s1, s2;
    for (long long i = 0; i < s.length(); i++) {
      if (i % 2 == 0) {
        s1 += s[i];
      } else {
        s2 += s[i];
      }
    }
    if (s2.length() == 0) {
      cout << stoi(s1);
    } else {
      cout << ((stoi(s1) + 1) * (stoi(s2) + 1) - 2);
    }
    cout << "\n";
  }
}
