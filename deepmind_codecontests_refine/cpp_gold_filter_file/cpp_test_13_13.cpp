#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a = 0, b = 0, c = 0;
    string line;
    cin >> line;
    for (char d : line) {
      if (d == 'B') b++;
      if (d == 'A') a++;
      if (d == 'C') c++;
    }
    if (b == a + c) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
