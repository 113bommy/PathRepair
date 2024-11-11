#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  for (int i = 0; i <= 9; ++i) {
    cout << i << flush << endl;
    string s;
    getline(cin, s);
    if (s == "no") continue;
    if (s == "no way" || s == "don't even" || s == "are you serious" ||
        s == "go die in a hole" || s == "worse" || s == "terrible")
      cout << "grumpy";
    else if (s == "cool" || s == "not bad" || s == "great" ||
             s == "don't touch me" || s == "don't think so")
      cout << "normal";
    return 0;
  }
}
