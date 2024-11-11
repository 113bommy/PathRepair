#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int steps = max(abs(int(s[0] - t[0])), abs(int(s[1] - t[1])));
  cout << steps << endl;
  while (s != t) {
    if (s[0] < t[0]) {
      s[0]++;
      cout << "R";
    }
    if (s[0] > t[0]) {
      s[0]--;
      cout << "L";
    }
    if (s[1] < t[1]) {
      s[1]++;
      cout << "D";
    }
    if (s[1] > t[1]) {
      s[1]--;
      cout << "U";
    }
    cout << endl;
  }
}
