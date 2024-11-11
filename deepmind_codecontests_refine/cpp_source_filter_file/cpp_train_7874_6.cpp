#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int i = 0; i < 10; i++) {
    cout << i << endl;
    string r;
    getline(cin, r);
    if (r == "terrible" || r == "worse" || r == "no way" ||
        r == "are you serious?" || r == "do die in a hole") {
      cout << "grumpy";
      return 0;
    }
    if (r == "cool" || r == "not bad" || r == "don't think so" ||
        r == "don't touch me!'" || r == "great!") {
      cout << "normal";
      return 0;
    }
  }
  return 0;
}
