#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a = 0, b = 0, c = 0;
    string line;
    cin >> line;
    for (char c : line) {
      if (c == 'B') b++;
      if (c == 'A') a++;
      if (c == 'C') c++;
    }
    if (b == a + c) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
