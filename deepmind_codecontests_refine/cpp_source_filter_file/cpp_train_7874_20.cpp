#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  for (int i = 0; i <= 9; i++) {
    cout << i << endl;
    cout << flush;
    a = "";
    getline(cin, a);
    if (a == "no") {
      continue;
    } else {
      if (a == "don't think so" || a == "great!" || a == "don't touch me!" ||
          a == "not bad" || a == "cool") {
        cout << "normal";
      } else {
        if (a == "are you serious?" || a == "worse" || a == "terrible" ||
            a == "don't even" || a == "no way" || a == "go die in a hole") {
          cout << "grumpy";
        } else {
          cout << "normal";
        }
      }
      return 0;
    }
  }
}
