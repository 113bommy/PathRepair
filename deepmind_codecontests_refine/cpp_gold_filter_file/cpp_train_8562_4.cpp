#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int cant = 1, times = 0;
  for (int i = 1; i < s.length(); i++) {
    if (s[i - 1] == s[i]) {
      if (cant < 5) {
        cant++;
      } else {
        cant = 1;
        times++;
      }
    } else {
      times++;
      cant = 1;
    }
  }
  times++;
  cout << times << endl;
}
