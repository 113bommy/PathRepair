#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int main() {
  int f = 0, g = 0;
  for (int i = 0; i <= 9; i++) {
    cout << i << "\n";
    string s;
    getline(cin, s);
    if (s == "no") f++;
    if (s == "don't touch me!" || s == "great!" || s == "don't think so" ||
        s == "not bad" || s == "cool") {
      g = 1;
      break;
    }
    if (s == "don't even" || s == "are you serious?" || s == "no way" ||
        s == "go die in a hole" || s == "worse" || s == "terrible") {
      g = 2;
      break;
    }
    if (f > 3) {
      g = 1;
      break;
    }
  }
  if (g == 1)
    cout << "normal\n";
  else
    cout << "grumpy\n";
  return 0;
}
