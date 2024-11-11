#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int a, c = 0;
  string b;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> b;
    if (b == "X++" || b == "++X") {
      c += 1;
    }
    if (b == "X--" || b == "--X") {
      c -= 1;
    }
  }
  cout << c;
}
