#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int main() {
  cin >> T;
  for (int x = 0; x < T; x++) {
    cin >> s;
    int total = 0, sum = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '-') {
        total--;
      } else {
        total++;
      }
      if (total < 0) {
        sum += i + 1;
        total++;
      }
    }
    sum += s.length();
    cout << sum << '\n';
  }
}
