#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  for (int i = 0; i < 10; ++i) {
    cout << i << endl;
    getline(cin, s);
    if (s == "worse" || s == "go die in a hole" || s == "are you serious?" ||
        s == "terrible" || s == "no way" || s == "don't even") {
      cout << "grumpy";
      break;
    } else {
      if (s == "great!" || s == "don't touch me!" || s == "don't think so" ||
          s == "not bad" || s == "cool") {
        cout << "normal";
        break;
      }
    }
  }
}
