#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, x = 0;
  cin >> a;
  string str;
  for (int i = 0; i < a + 1; i++) {
    getline(cin, str);
    if ((str.compare("++X")) == 0) {
      ++x;
    } else if ((str.compare("--X")) == 0) {
      --x;
    } else if ((str.compare("X++")) == 0) {
      x++;
    } else if ((str.compare("X--")) == 0) {
      x--;
    }
  }
  cout << x;
  return 0;
}
